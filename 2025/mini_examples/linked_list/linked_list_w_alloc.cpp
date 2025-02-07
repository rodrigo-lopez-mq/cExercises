

#include <stdexcept>
#include <memory>
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
  class Node {
  public:
    unique_ptr<T> _data;
    Node* left;
    Node* right;

    Node(unique_ptr<T> data) : _data(move(data)), left(nullptr), right(nullptr) {}
  };

public:
  LinkedList() : _head(nullptr), _size(0) {}

  void push_back(T obj) {
    unique_ptr<T> data = make_unique<T>(move(obj));
    if (!_head) {
      _head = new Node(move(data));
    } else {
      Node* current = _head;
      while (current->right) {
        current = current->right;
      }
      current->right = new Node(move(data));
    }
    ++_size;
  }

  T peek() {
    if (!_head) {
      throw std::runtime_error("List is empty");
    }
    return *_head->_data;
  }

  ~LinkedList() {
    Node* current = _head;
    while (current) {
      Node* next = current->right;
      delete current;
      current = next;
    }
  }

  size_t size() {
    return _size;
  }

  T get(uint32_t idx) {
    if (idx > _size) {
      throw std::out_of_range("Index out of range");
    }
    Node* current = _head;
    for (int32_t i = 0; i < idx; i++) {
      current = current->right;
    }
    return *(current->_data);
  }

private:
  Node* _head;
  size_t _size;
};

typedef struct {
  int val;
  bool set;
}mydata_t;

int main()
{
  LinkedList<mydata_t> myList;

  myList.push_back({5, false});
  myList.push_back({6, true});
  myList.push_back({7, false});
  myList.push_back({8, true});
  myList.push_back({9, false});

  for (int i = 0; i < myList.size(); i++) {
    auto item = myList.get(i);
    cout << item.val << endl;
  }

	return 0;
}
