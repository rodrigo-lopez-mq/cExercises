#include <iostream>
#include <cstring>
#include <cstdlib>
//#include <string>
//#include <fstream>
//#include <cstdarg>
//#include <stack>
//#include <vector>

using namespace std;

int reverse (int number)
{
    int output=0;
    string temp;

    temp=to_string(number);

    char *a=&temp[0];
    char *b=&temp.back();
    char t;

    for (int i=0;i<(temp.size()/2);i++)
    {
        t=*a;
        *a=*b;
        *b=t;
        a++;
        b--;
    }


    output=stoi(temp);

    cout<<temp<<endl;

    return output;
}

string reverse (string number)
{


    char *a=&number[0];
    char *b=&number.back();
    char t;

    for (int i=0;i<(number.size()/2);i++)
    {
        t=*a;
        *a=*b;
        *b=t;
        a++;
        b--;
    }


    return number;
}

int main()
{

    cout<<reverse(4567)<<endl;

    cout<<reverse("Saludos")<<endl;

    cout<<"\n";
    //cout<<i;
}
