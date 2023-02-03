#include <iostream>
#include <string>
using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string name = "", string telnum = "", string address = "") {
		this->name = name;
		this->telnum = telnum;
		this->address = address;
	}
	friend ostream& operator << (ostream& os, Phone ph);
	friend istream& operator >> (istream& ins, Phone& ph);
};

ostream& operator << (ostream& os, Phone ph) {
	cout << "(" << ph.name << "," << ph.telnum << "," << ph.address << ")";
	return os;
}

istream& operator >> (istream& ins, Phone& ph) {
	cout << "�̸�:";
	getline(ins,ph.name);
	cout << "��ȭ��ȣ:";
	getline(ins,ph.telnum);
	cout << "�ּ�:";
	getline(ins,ph.address);
	return ins;
}
int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}