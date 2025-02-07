#include <iostream>

using namespace std;

int main() {
	const int a = 5;
	cout << a << endl;
	
	int* x = (int*)&a;
	*x = 6;
	cout << *x << endl;
	cout << a << endl;
	// Aqui el valor de *x cambia pero al de a no cambia

	int* y = const_cast<int*>(&a);
	*y = 7;
	cout << *x << endl;
	cout << a << endl;
	// Aqui el valor de *y cambia pero al de a no cambia

	return 0;
}