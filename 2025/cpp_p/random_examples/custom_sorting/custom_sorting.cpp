#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>

auto lamdaSort = [] (int& a, int& b) {return a > b;};

struct structSort {
  bool operator()(int& a, int& b) {return a < b;};
};

class classSort {
public:
  bool operator()(int& a, int& b) {return a > b;};
};

void exampleVector() {
  std::vector<int> v1 = {5,3,8,2,9,5,3,9,1};
  std::vector<int> vsort(v1);

  std::cout << "v1: ";
  for (auto& x : v1) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::sort(vsort.begin(), vsort.end(), lamdaSort);

  std::cout << "vsort: ";
  for (auto& x : vsort) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  vsort = v1;
  std::sort(vsort.begin(), vsort.end(), structSort());

  std::cout << "vsort: ";
  for (auto& x : vsort) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  vsort = v1;
  std::sort(vsort.begin(), vsort.end(), classSort());

  std::cout << "vsort: ";
  for (auto& x : vsort) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

void exampleQueue() {
  std::cout << std::endl;
  std::vector<int> v1 = {5,3,8,2,9,5,3,9,1};
  std::priority_queue<int, std::vector<int>, decltype(lamdaSort)> pq(lamdaSort);

  for (auto& x : v1) {
    pq.push(x);
  }

  std::cout << "queue: ";
  while (!pq.empty()) {
    auto x = pq.top();
    std::cout << x << " ";
    pq.pop();
  }
  std::cout << std::endl;


  std::priority_queue<int, std::vector<int>, structSort> pq2;
  std::cout << "queue: ";
  while (!pq2.empty()) {
    auto x = pq2.top();
    std::cout << x << " ";
    pq2.pop();
  }
  std::cout << std::endl;  

  std::priority_queue<int, std::vector<int>, classSort> pq3;
  std::cout << "queue: ";
  while (!pq3.empty()) {
    auto x = pq3.top();
    std::cout << x << " ";
    pq3.pop();
  }
  std::cout << std::endl;  
}

int main() {
  exampleVector();
  exampleQueue();


  return 0;
}