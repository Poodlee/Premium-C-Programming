#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream fin("c:\\windows\\system.ini", ios::in);
	if (!fin) {
		cout << "���� ���� ����!!" << endl;
		return 0;
	}
	string line;
	int i = 1;
	while (getline(fin, line)) {	// �� ���ξ� �д´�.
		cout << i++ << " : " << line << endl;
	}
	fin.close();
}