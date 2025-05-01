import csv
from collections import defaultdict
from datetime import datetime

def analyze_crypto_report(file_path, fiat_currency="CAD"):
    """
    Analyzes a crypto transaction report in CSV format and reports realized gains and losses.

    Args:
        file_path (str): The path to the CSV file.
        fiat_currency (str): The fiat currency for gain/loss calculation (default: CAD).

    Returns:
        dict: A dictionary containing the summary of the data, including realized gains/losses.
    """
    transactions = []
    with open(file_path, 'r', newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            transactions.append(row)

    holdings = defaultdict(float)
    cost_basis = defaultdict(float)
    realized_gains_losses = defaultdict(float)
    total_realized_gain_loss = 0.0

    # Sort transactions by date
    transactions.sort(key=lambda x: datetime.fromisoformat(x['date'].replace('Z', '+00:00')))

    for tx in transactions:
        sent_amount_str = tx.get('Sent Amount')
        sent_currency = tx.get('Sent Currency')
        received_amount_str = tx.get('Received Amount')
        received_currency = tx.get('Received Currency')
        fee_amount_str = tx.get('Fee Amount')
        fee_currency = tx.get('Fee Currency')
        label = tx.get('Label')

        sent_amount = float(sent_amount_str) if sent_amount_str else 0.0
        received_amount = float(received_amount_str) if received_amount_str else 0.0
        fee_amount = float(fee_amount_str) if fee_amount_str else 0.0

        # Deposit (Buying crypto with fiat)
        if sent_currency == fiat_currency and received_currency and received_amount > 0:
            holdings[received_currency] += received_amount
            cost_basis[received_currency] += sent_amount  # Cost basis in fiat

        # Withdrawal (Selling crypto for fiat)
        elif received_currency == fiat_currency and sent_currency and sent_amount > 0:
            if holdings[sent_currency] >= sent_amount:
                average_cost = cost_basis[sent_currency] / holdings[sent_currency] if holdings[sent_currency] > 0 else 0
                proceeds = received_amount - (fee_amount if fee_currency == fiat_currency else 0)
                gain_loss = proceeds - (average_cost * sent_amount)
                realized_gains_losses[sent_currency] += gain_loss
                total_realized_gain_loss += gain_loss
                holdings[sent_currency] -= sent_amount
                cost_basis[sent_currency] -= average_cost * sent_amount
            else:
                print(f"Warning: Insufficient balance of {sent_currency} to withdraw {sent_amount} in transaction: {tx['TxHash']}")

        # Sending crypto to another address (not a realized gain/loss unless cost basis is known and tracked out)
        elif sent_currency and sent_amount > 0 and received_currency != fiat_currency and sent_currency != fiat_currency:
            if holdings[sent_currency] >= sent_amount:
                average_cost = cost_basis[sent_currency] / holdings[sent_currency] if holdings[sent_currency] > 0 else 0
                cost_of_transfer = average_cost * sent_amount
                holdings[sent_currency] -= sent_amount
                cost_basis[sent_currency] -= cost_of_transfer
            else:
                print(f"Warning: Insufficient balance of {sent_currency} to send {sent_amount} in transaction: {tx['TxHash']}")

        # Receiving crypto (e.g., from another address, not a direct fiat purchase)
        elif received_currency and received_amount > 0 and sent_currency != fiat_currency:
            # For simplicity, we don't assign a cost basis here unless it was a direct fiat purchase.
            # Rewards might be considered to have a zero cost basis initially.
            holdings[received_currency] += received_amount
            if label and label.lower() == 'reward':
                pass # Reward has no initial cost basis in this simple model
            elif not sent_currency:
                # Received without sending fiat, no immediate cost basis assigned
                pass

        # Fees (if paid in crypto, reduce holdings and cost basis proportionally)
        if fee_amount > 0 and fee_currency and holdings.get(fee_currency, 0) >= fee_amount:
            average_cost_fee_currency = cost_basis[fee_currency] / holdings[fee_currency] if holdings[fee_currency] > 0 else 0
            cost_of_fee = average_cost_fee_currency * fee_amount
            holdings[fee_currency] -= fee_amount
            cost_basis[fee_currency] -= cost_of_fee
            if fiat_currency == fee_currency:
                total_realized_gain_loss -= fee_amount # Fees in fiat are a direct expense

    summary = {
        "realized_gains_losses": dict(realized_gains_losses),
        "total_realized_gain_loss": total_realized_gain_loss,
        "fiat_currency": fiat_currency,
        "final_holdings": dict(holdings),
        "final_cost_basis": dict(cost_basis),
    }
    return summary

if __name__ == "__main__":
    file_path = input("Enter the path to your crypto report CSV file: ")
    fiat = input(f"Enter your fiat currency (e.g., CAD, USD - default: CAD): ") or "CAD"
    try:
        summary = analyze_crypto_report(file_path, fiat)
        print(f"\n--- Realized Gains and Losses (in {summary['fiat_currency']}) ---")
        if summary['realized_gains_losses']:
            for token, gain_loss in summary['realized_gains_losses'].items():
                print(f"{token}: {gain_loss:.2f}")
        else:
            print("No realized gains or losses calculated based on the provided data and assumptions.")
        print(f"\nTotal Realized Gain/Loss (approximate in {summary['fiat_currency']}): {summary['total_realized_gain_loss']:.2f}")

        print("\n--- Final Holdings ---")
        for token, amount in summary['final_holdings'].items():
            print(f"{token}: {amount:.8f}")

        print("\n--- Remaining Cost Basis (in {summary['fiat_currency']}) ---")
        for token, cost in summary['final_cost_basis'].items():
            print(f"{token}: {cost:.2f}")

        print("\n--- Important Notes on Realized Gains/Losses ---")
        print("- This calculation assumes a First-In, First-Out (FIFO) method for determining the cost basis of sold cryptocurrencies.")
        print("- Realized gain/loss is primarily calculated when cryptocurrency is sold for the specified fiat currency.")
        print("- Transactions between different cryptocurrencies are NOT considered realized gains/losses in this simplified model.")
        print("- The accuracy depends on the completeness and correctness of your transaction history, especially regarding fiat purchases.")
        print("- Rewards received are currently considered to have a zero cost basis.")
        print("- Further refinement is needed to handle more complex scenarios like trading pairs and specific accounting methods.")

    except FileNotFoundError:
        print(f"Error: File not found at '{file_path}'")
    except Exception as e:
        print(f"An error occurred: {e}")


    # filename = 'C:\\Users\\r\\Downloads\\tax\\crypto_transaction_summary.csv'  # Replace with your CSV file name
