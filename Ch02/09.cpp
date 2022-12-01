#include <iostream>
#include <string>
using namespace std;

int main() {

	string name, address, age;
	cout << "이름은?\n";
	getline(cin, name);
	cout << "주소는?\n";
	getline(cin, address);
	cout << "나이는?\n";
	getline(cin, age);

	cout << name << "," << address << "," << age << "세";

}