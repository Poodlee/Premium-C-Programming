#include <iostream>
#include <fstream>
using namespace std;

int main() {
	fstream fin("c:\\temp\\test.txt", ios::in);
	if (!fin) {
		cout << "���� ���� ���� !" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF) {
		cout.put(ch);
	}
	fin.close();
}