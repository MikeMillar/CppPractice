#include <iostream>
using namespace std;

// Could declare variables here! -- string text2[] = { "apple", "orange", "bannana" };

class Animal {
	string name;

public:
	Animal() { cout << "Animal Created." << endl; };
	Animal(const Animal& other) { cout << "Animal created by copying." << endl; };
	~Animal() { cout << "Destructor called." << endl; };
	void setName(string name) { this->name = name; };
	void speak() const { cout << "My name is: " << name << endl; };
};

void show1(string texts[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << texts[i] << endl;
	}
}

void show2(string *texts, const int n) {
	for (int i = 0; i < n; i++) {
		cout << texts[i] << endl;
	}
}

void show3(string (&texts)[3]) {
	for (int i = 0; i < sizeof(texts)/sizeof(string); i++) {
		cout << texts[i] << endl;
	}
}

string* getArray() {
	// Don't return pointers to local variables -- string text2[] = { "apple", "orange", "bannana" };
	string* pMem = new string[10];
	return pMem;
}

void freeMemory(string* pMem) {
	delete[] pMem;
}

int main() {

	const double PI = 3.141592;
	cout << PI << endl;

	Animal animal;
	Animal animal2 = animal;
	animal.setName("Freddy");
	animal2.setName("Mike");
	animal.speak();
	animal2.speak();

	Animal* pCat = new Animal(); // Wherever you call new, always call delete. Or you will have memory leaks.
	pCat->setName("George");
	pCat->speak();
	delete pCat;

	int value = 8;
	//const int* const pValue = &value; // const int* const pValue = &value; --- Compiler reads as a const int, and a const pointer. Can't change either.
	int* pValue = &value;
	cout << *pValue << endl;

	int num = 11;
	pValue = &num; // Error with this: int* const pValue = &value; --- Compiler reads the pointer as a const, so can't change what the pointer is pointing to.
	*pValue = 12; // Error with this: const int* pValue = &value; --- Compilers reads this as the value the pointer is pointing to is constant. So error when trying to change value
	cout << *pValue << endl;

	string texts[] = {"one", "two", "three"};
	show3(texts);

	string* pMemory = getArray();
	freeMemory(pMemory);


	return 0;
}