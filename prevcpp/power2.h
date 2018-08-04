#include <iostream>
//#include <cstring>


using namespace std;

void pow()
{
    unsigned int size=500;
    unsigned int array[size];
    unsigned int result=0;

    for (int i=0; i<size;i++)
    {
        array[i]=0;

    }

    /////////////////////

    array[0]=2;

    unsigned int a=0;
    unsigned int carry=0;
    unsigned int flag=0;

    for(int i=1;i<1000;i++)
    {
        for (int k=0;k<size;k++)
        {
            a=array[k];
            a*=2;
            //if(a==0){flag++; if(flag>4){break;}}

            a+=carry;

            carry=0;



            if(a>9)
            {
                carry=1;
                a%=10;
            }
            //if(a!=0){cout<<a<< " "<< endl;}
            array[k]=a;

        }



    }

    /////////////////////


    for (int i=size-1; i>=0;i--)
    {
        result+=array[i];

        if(array[i]!=0){cout<<array[i]<< " " ;}
    }
    cout<<""<<endl;
    cout<<result<<endl;
    //cout<<result<<endl;

}


int main()
{

    pow();

    cout<<"END"<<endl;

    return 0;
}
