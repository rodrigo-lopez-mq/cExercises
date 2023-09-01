#include <iostream>
using namespace std;

//We need to read the tag
//if it is the tag we are looking for we need its value
//if not, we need to know its lenght and go to the next tag
//

void TLV (char *input, unsigned char tag, unsigned char arraySize)
{
    unsigned char length;

    for (unsigned char k=0; k<arraySize;k++)
    {

        if (tag==*input)
        {
            printf("%x\n",*input);
            input++;
            length=*input+1;
            arraySize-=length;
            input++;

            for (unsigned char i=0; i<length-1;i++)
            {
                printf("%x\n",*input++);
                //input++;
            }

        }
        else
        {
            input++;
            length =*input+1;
            input+=length;
            arraySize-=length;
        }

    }

}

/*

A TLV is a tag, length, value byte array.
Examples:
The byte array [ 0x5A, 0x02, 0x01, 0x02 ] contains a single TLV.
T1L1V1T2L2V2...




*/
// To execute C++, please define "int main()"
int main() {

    char tlv_input[]{ 0x57, 0x04, 0x01, 0x02, 0x03, 0x04, 0x56, 0x06, 0x01, 0x02, 0x03,   0x04, 0x05, 0x06, 0x53, 0x02, 0x08, 0x40, 0x50, 0x02, 0x30, 0x31};
    unsigned char arraySize = sizeof(tlv_input)/sizeof(char);

    TLV(tlv_input,0x50,arraySize);
    return 0;
}
