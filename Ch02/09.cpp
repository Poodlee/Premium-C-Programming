#include <iostream>
#include <string>
using namespace std;

int main() {

	string name, address, age;
	cout << "�̸���?\n";
	getline(cin, name);
	cout << "�ּҴ�?\n";
	getline(cin, address);
	cout << "���̴�?\n";
	getline(cin, age);

	cout << name << "," << address << "," << age << "��";

}