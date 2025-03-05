#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

std::mutex mtx;
std::condition_variable condition;

int add(int a, int b) {
  std::cout << a+b << std::endl;
  return a+b;
}

void waiter_thread() {
  std::unique_lock<std::mutex> lock(mtx);
  std::cout << "Waiting" << std::endl;
  condition.wait(lock);
  std::cout << "Done" << std::endl;
}

void sender_thread() {
  std::unique_lock<std::mutex> lock(mtx);
  std::cout << "Sending" << std::endl;
  condition.notify_all();
  std::cout << "Sent" << std::endl;
}

int main() {

  std::thread t(std::bind(add, 3, 5));
  t.join();

  std::thread waiter(waiter_thread);
  std::thread sender(sender_thread);
  sender.join();
  waiter.join();

  return 0;
}