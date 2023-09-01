#include <iostream>
 
using namespace std;

  typedef int *pointer;

void func2(pointer* p)
{
	**p=4;
}

void func1(int* value, pointer* p)
{
	**p=5;
	cout<< *value<<endl;
	func2(p);
	*value=0;
}

void dostuff(double (*a)[3][3])
{
// access them as (*a)[0][0] .. (*a)[2][2]
}


int main()
{
  cout<<"sup"<<endl;

  int number = 8;
  int value = 9;
  pointer p = &number;

  double stuff[3][3];
  double (*p_stuff)[3][3] = &stuff;
  dostuff(p_stuff);

  // void * pointer = &number;

  func1(&value, &p);
  // void func2();

  cout<<*p<<endl;
  cout<<value<<endl;

  return 0;
}