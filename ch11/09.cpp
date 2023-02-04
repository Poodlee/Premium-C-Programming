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
	ins >> ph.name;
	ins.ignore(100,'\n');
	cout << "전화번호:";
	ins >> ph.telnum;
	ins.ignore(100,'\n');
	cout << "주소:";
	ins >> ph.address;
	ins.ignore(100,'\n');
	return ins;
}
int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;
}