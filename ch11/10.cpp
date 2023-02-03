#include <iostream>
#include <string>
using namespace std;

istream& prompt(istream& ins) {	// 입력 prompt 조작자
	cout << "암호?";
	return ins;
}

int main() {
	string password;
	while (1) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		else
			cout << "login fail. try again!!" << endl;
	}
}