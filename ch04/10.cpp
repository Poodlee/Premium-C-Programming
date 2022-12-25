#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person() { name = ' '; }
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person* p;
	string FamliyName;
	int size; 
public:
	Family(string name, int size) { p = new Person[size];  this->size = size; this->FamliyName = name; }
	void setName(int num, string named) { p[num].setName(named); }
	void show();
	~Family() { delete[]p; }
};

void Family::show() {
	cout << FamliyName << "가족은 다음과 같이 3명입니다. \n";
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << '\t';
	}
	cout << endl;
}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();
	delete simpson;
}