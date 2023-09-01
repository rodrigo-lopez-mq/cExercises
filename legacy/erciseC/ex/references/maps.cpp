#include <iostream>
#include <map>
#include <string>

// using  namespace std;
// void function1(map<string, string> &mapa)
// {
// 	map<string, string> MyMap2;
// 	map<string,string>::iterator it;

// 	for ( it=mapa.begin() ; it != mapa.end(); it++ )
// 	{
// 		//cout << (*it).first << " => " << (*it).second << endl;
// 		MyMap2.insert ( pair<string,string>((*it).first,(*it).second) );
// 	}

// 	for ( it=MyMap2.begin() ; it != MyMap2.end(); it++ )
// 	{
// 		cout << (*it).first << " => " << (*it).second << endl;
		
// 	}

// }

// void function2(const void* input)
// {

//     map<string, string> MyMap2 = *((map<string, string>*)input);
// 	map<string,string>::iterator it;

// 	for ( it=MyMap2.begin() ; it != MyMap2.end(); it++ )
// 	{
// 		cout << (*it).first << " => " << (*it).second << endl;
// 	}

// }

// int main()
// {

// 	map<string, string> MyMap;
// 		map<string,string>::iterator it;

// MyMap.insert ( pair<string,string>("one","uno") );
// MyMap.insert ( pair<string,string>("two","dos") );

// for ( it=MyMap.begin() ; it != MyMap.end(); it++ )
// 		cout << (*it).first << " => " << (*it).second << endl;

// // function1(MyMap);
// 	function2(&MyMap);

// 	return 0;
// }

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  std::map<char,int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  std::map<char,int> second (first.begin(),first.end());
    std::map<char,int>::iterator it;

first.insert ( std::pair<char,int>('z',11) );


  for ( it=first.begin() ; it != first.end(); it++ )
     std::cout << (*it).first << " => " << (*it).second << std::endl;

  return 0;
}