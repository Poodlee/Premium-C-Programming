#include <iostream>
#include <string>
using namespace std;

class Integer {
public:
	int num;
	Integer(int num) { this -> num = num;}
	Integer(string Data) { this -> num = stoi(Data); }
	int get() { return num; }
	bool isEven() {
		if (num % 2 == 0)return true;
		else return false;
	}
	void set(int num) { this->num = num; }
};


int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
}