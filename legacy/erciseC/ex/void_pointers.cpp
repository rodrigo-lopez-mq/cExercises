#include <iostream>

using namespace std;

typedef void *qcarcam_hndl_t;
typedef void *one;
typedef void *two;
typedef void *three;

// x=*((int *)value)
// *(int *)(value) = x

struct thestructure {
  int device;
  int source;
};

int onefunction(void *value) {
  // cout<<"Yup"<<endl;

  cout << *((int *)value) << endl;

  return 0;
}

int twofunction(void *value) {
  int e = 9;
  *(int *)(value) = e;
  return 0;
}

two threefunction(qcarcam_hndl_t input) {
  int six = 66;
  input = &six;

  // cout<<"yyy"<<endl;
  return (two)input;
}

void fourfunction(qcarcam_hndl_t input) { cout << *((int *)input) << endl; }

void fivefunction(unsigned int input) {
  if (5 >= 2) {
    cout << input << " --fivefunction" << endl;
  }
}

int main() {

  qcarcam_hndl_t y;

  three test;
  int u = 6;
  int minus = -5;
  y = &u;

  thestructure structure;

  structure.device = 11;
  structure.source = 22;

  onefunction(y);

  twofunction(y);

  two ret = threefunction((qcarcam_hndl_t)test);

  test = (three)ret;

  cout << *((int *)test) << " end" << endl;

  test = &structure;

  cout << *((int *)test) << " end 2" << endl;

  fourfunction(&u);

  double d = 3.2; // = u;

  u = (int)d;

  cout << u << endl;

  fivefunction(minus);

  cout << "Suh" << endl;
}
