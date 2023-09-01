
#include <cstdlib>
#include <iostream>

#define NUMBER 6

using namespace std;

template <typename T> T meh(T a, T b)
{
	return a+b;
}

class Shape
{
public:
    Shape()
    {
        x=0;
    }
    int getX()
    {
        return x;
    }
    void setX(int n)
    {
        x=n;
    }
    virtual int getVal()
    {
        return NUMBER;
    }
protected:
    int x;
};

class Point : public Shape
{
public:
    Point()
    {
        x=-1;
        p=-1;
    }
    int dosX()
    {
        return x*x;
    }
    int getP()
    {
        return p;
    }
    int getVal()
    {
        return 8;
    }
    
private:
    int p;
    
};

class A
{
public:
    A(int n)
    {
        x=n;
    }
    
//    int getX()
//    {
//        return x;
//    }
    
//private:
    int x;
};

class B: public A 
{
public:
    B(int n): A(n)
    {
        x=n;
    }
    
    int getX()
    {
        return x;
    }
    
};

//int main(int argc, char **argv)
//{
//	cout<<""<<endl;
//	
//        Shape *shape=new Shape();
//        shape->setX(3);
//        shape->setX(7);
//        
//        Point *point = new Point();
//        point->getX();
//        
//        Shape *s = new Point();
//        
//	
//	cout<<"Shape "<<shape->getVal()<<endl;
//        
//        cout<<"Point "<<point->getVal()<<endl;
//        
//        cout<<"S "<<s->getVal()<<endl;
//	
//	return 0;
//}

