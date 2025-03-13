import os
from selenium import webdriver
from selenium.webdriver.firefox.service import Service
from selenium.webdriver.firefox.options import Options
from webdriver_manager.firefox import GeckoDriverManager
from selenium.common.exceptions import TimeoutException
import time
from bs4 import BeautifulSoup

def get_modal_content(url, timeout=30):
    driver = None
    try:
        options = Options()
        # options.add_argument('--headless')
        service = Service(GeckoDriverManager().install())
        driver = webdriver.Firefox(service=service, options=options)
        driver.set_page_load_timeout(timeout)
        driver.get(url)
        time.sleep(3)

        soup = BeautifulSoup(driver.page_source, 'html.parser')

        schedule_buttons = soup.find_all('button', class_='launchModal btn btn-default')

        modal_contents = []
        if schedule_buttons:
            # Find the button using a CSS selector
            button_selector = ".launchModal.btn.btn-default"

            # Execute JavaScript to click the button
            driver.execute_script(f"""
                document.querySelectorAll('{button_selector}')[0].click();
            """)
            time.sleep(2)

            soup2 = BeautifulSoup(driver.page_source, 'html.parser')

            script_dir = os.path.dirname(os.path.abspath(__file__))
            file_path = os.path.join(script_dir, "modal_content.html")

            with open(file_path, "w", encoding="utf-8") as f:
                f.write(soup2.prettify())

            modal = soup2.find('div', class_='modal-content')

            table_div = modal.find("div", class_="modal fade modalTemplate in", role_="dialog")  
            print(table_div)
            # table_div = modal.find("div", class_="table-responsive")  
            # print(table_div)            
            # schedule_table = table_div.find("table", id="dropintableData")
            # print(schedule_table)

            if modal:
                modal_contents.append(str(modal))
            else:
                modal_contents.append("Modal not found.")
        else:
            modal_contents.append("Schedule button not found.")

        return modal_contents

    except TimeoutException:
        print("Error: Page load timed out.")
        return None
    except Exception as e:
        print(f"Error: {e}")
        return None
    finally:
        if driver:
            driver.quit()

if __name__ == "__main__":
    url = "https://www.toronto.ca/explore-enjoy/parks-recreation/program-activities/ice-snow-activities/public-leisure-skating/"
    modal_content = get_modal_content(url)

    if modal_content:
        for content in modal_content:
            print("Modal Content:")
            # print(content)
    else:
        print("Failed to retrieve modal content.")