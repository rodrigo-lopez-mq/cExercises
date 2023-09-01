#include <iostream>
#include <cstring>
#include <cstdlib>
//#include <cstdarg>
//#include <stack>
//#include <vector>

using namespace std;

class A
{
protected:
    int x=0;
public:
    void setX(int &number)
    {
        x=number;
    }

    const int getX()
    {
        return x;
    }

    virtual void message()
    {
        cout<<"A messgae"<<endl;
    }

};

class C
{
protected:
    string message="This is a message";

public:
    void setmessage(string m)
    {
        message=m;
    }
    string getmessage()
    {
        return message;
    }

};

class B : public A, public C
{
public:
    void message()
    {
        cout<<"B messgae"<<endl;
    }
};

int main()
{

    int cuatro=6;


    A *a = new A();
    C *c = new C();
    B *b = new B();
    A *aa = new B();


    a->setX(cuatro);


    cout<<a->getX()<<endl;
    cout<<c->getmessage()<<endl;

    b->setmessage("Saludos");


    cout<<c->getmessage()<<endl;
    cout<<b->getmessage()<<endl;

//    a->message();
//    b->message();
    aa->message();

    delete(a);
    delete(c);
    delete(b);
    delete(aa);

    cout<<"\n";
    //cout<<i;
}
