#include <iostream>
#include <cstring>
#include <cstdlib>
//#include <fstream>
//#include <cstdarg>
//#include <stack>
//#include <vector>

using namespace std;



int main()
{
    ofstream myfile;
    myfile.open ("C:\\Users\\R\\Desktop\\joven.txt");

    for (int i=1;i<=100;i++)
    {
        for (int k=1;k<=i;k++)
        {
            myfile << "joven ";
        }
        myfile <<endl;
    }


    //myfile << "joven\n";
    myfile.close();


    cout<<"\n";
    //cout<<i;
}
