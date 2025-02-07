#include <iostream>
#include <vector>

using namespace std;

class MyClass {
public:
	MyClass() = default;

	int value_;
	float fvalue_;
	vector<int> vector_;
	unique_ptr<int> ptr_;

	void printContent(void);

	// Copy operator
	MyClass& operator=(const MyClass& other) {
		if (this == &other) {
			return *this;
		}

		value_ = other.value_;
		fvalue_ = other.fvalue_;
		vector_ = other.vector_;
		ptr_ = other.ptr_ ? std::make_unique<int>(*other.ptr_) : nullptr;
		return *this;
	}

	// Move operator
	MyClass& operator=(MyClass&& other) noexcept {
		if (this == &other) {
			return *this;
		}

		value_ = other.value_;
		fvalue_ = other.fvalue_;
		vector_ = move(other.vector_);
		ptr_ = move(other.ptr_);
		return *this;
	}

	bool operator>(MyClass& other) {
		return this->value_ > other.value_;
	}

	// Move constructor
	MyClass(MyClass&& other) noexcept
		: value_(other.value_), fvalue_(other.fvalue_), vector_(std::move(other.vector_)), ptr_(std::move(other.ptr_)) {
	}

	// Copy Constructor
	MyClass(const MyClass& other)
		: value_(other.value_), fvalue_(other.fvalue_), vector_(other.vector_), ptr_(other.ptr_ ? std::make_unique<int>(*other.ptr_) : nullptr) {
	}
private:
};

void MyClass::printContent() {
	cout << value_ << endl;
	cout << fvalue_ << endl;
	for (auto& x : vector_) {
		cout << x << endl;
	}
	if (ptr_) {
		cout << *ptr_ << endl;
	}
	cout << "-------" << endl;
}

int main() {

	MyClass mc;

	mc.value_ = 2;
	mc.fvalue_ = 6.1;

	vector<int> v = {1,2,3,4,5,6};
	mc.vector_ = move(v);
	mc.ptr_ = make_unique<int>(99);

	mc.printContent();

	MyClass mc2;
	mc2 = mc;

	mc2.printContent();

	MyClass mc3;
	mc3 = move(mc);
	mc3.printContent();

	MyClass mc_copy(mc3);
	mc_copy.value_ = 9;
	MyClass mc_move(std::move(mc2));

	cout << "Compare" << endl;
	cout << (mc_copy > mc_move) << endl;

	return 0;
}