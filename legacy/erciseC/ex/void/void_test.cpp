#include <iostream>
#include <stdlib.h>

using namespace std;

// capture_context_t context = (capture_context_t)hndl;
// qcarcam_buffer_t *pointers_vcap = (qcarcam_buffer_t*)calloc(p_buffers->n_buffers,sizeof(void*));

typedef void *qcarcam_hndl_t;
typedef int *ppointer;

struct thestruct
{
  int one;
  bool two;
};

// x=*((int *)value)
// *(int *)(value) = x

qcarcam_hndl_t func1()
{

}

int main() {

  thestruct array[5];

  for (int i=0; i<5; i++)
  {
    array[i].one = 5;
    array[i].two = true;
  }

  void *pointer = &array;

  thestruct *cosa = (thestruct*)calloc(5,sizeof(void*));

  
  cosa[3] = *(thestruct*)pointer;

  cosa+=3;

  cout << cosa->one << endl;

  cout << "Suh" << endl;
}
