
#include <cstdlib>
#include <iostream>
//#include <list>

#define NUMBER 6

using namespace std;

#define MUL(A,B) ((A)<(B) ? B : A)

#define POW(A) (A*A)

int main(int argc, char **argv)
{
    int a=3;
    int b=4;

    cout<<MUL(a,b)<<endl;
    cout<<POW(a)<<endl;
    
	return 0;
}

