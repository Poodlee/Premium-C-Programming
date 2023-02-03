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
	cout << "이름:";
	getline(ins,ph.name);
	cout << "전화번호:";
	getline(ins,ph.telnum);
	cout << "주소:";
	getline(ins,ph.address);
	return ins;
}
int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}