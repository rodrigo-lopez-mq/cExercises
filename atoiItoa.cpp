#include <iostream>
#include <cstring>
//#include <cstdarg>
#include <stack>

using namespace std;


char *turboitoa(int num)
{
    int size=1;
    int c=num;

    while(c>10)
    {
        size++;
        c/=10;
    }

    //cout<<size<<endl;

    char str[size];
    int i=0;

    while(i<size)
    {
        str[i]=num%10+'0';
        i++;
        num/=10;
    }

    char *first=str;
    char *end=str+(size-1);
    char temp;
//    cout<<*first<<endl;
//    cout<<*end<<endl;

    for(int i=0;i<size/2;i++)
    {
        temp=*first;
        *first=*end;
        *end=temp;
        first++;
        end--;
    }

    return str;
}

int turboatoi(char str[])
{
    //cout<<str<<endl;
    int i=0;
    int result=0;

    while(str[i]>47 && str[i]<58)
    {
        result*=(10);
        result+=((str[i]-'0'));

        i++;
    }

    return result;
}

int main()
{
    char str[]="52689";
    int num=52687;
    char ret[10];
    int res=0;

    //char *result=turboitoa(num);
    //strcpy(ret,result);

    res=turboatoi(str);

    cout<<res;

    cout<<"\n";
    //cout<<i;
}
