#include <iostream>
using namespace std;

class Animal {
	string name;

public:
	Animal() { cout << "Animal Created." << endl; };
	Animal(const Animal& other) { name = other.name; cout << "Animal created by copying." << endl; }; // Custom copy constructor. c++ has is own copy constructor it uses by default.
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is: " << name << endl; };
};

int main() {

	const double PI = 3.141592;
	cout << PI << endl;

	Animal animal;
	Animal animal2 = animal;
	animal2.speak();
	animal.setName("Freddy");
	animal2.setName("Mike");
	animal.speak();
	animal2.speak();

	int value = 8;
	//const int* const pValue = &value; // const int* const pValue = &value; --- Compiler reads as a const int, and a const pointer. Can't change either.
	int* pValue = &value;
	cout << *pValue << endl;

	int num = 11;
	pValue = &num; // Error with this: int* const pValue = &value; --- Compiler reads the pointer as a const, so can't change what the pointer is pointing to.
	*pValue = 12; // Error with this: const int* pValue = &value; --- Compilers reads this as the value the pointer is pointing to is constant. So error when trying to change value
	cout << *pValue << endl;

	return 0;
}