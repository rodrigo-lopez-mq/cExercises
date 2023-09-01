#include <iostream>
//#include <cstring>
//#include <map>
//#include <string>

using namespace std;

class Food
{
protected:
    string name;
public:

    Food()
    {
        name="Please give me a name";
    }
    virtual void setName(string line)=0;
    virtual const string getName()=0;
};

class Pasta : public Food
{
public:
    Pasta()
    {
        name="Pasta";
    }
    void setName (string line)
    {
        name.append(" "+line);
    }
    const string getName()
    {
        return name;
    }
};

int main()
{
    Pasta pasta;

    pasta.setName("One");

    cout<<pasta.getName()<<endl;

    //string s="Hola";

    //cout<<s<<endl;

    return 0;
}
