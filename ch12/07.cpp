#include <iostream>
#include <fstream>
using namespace std;
// ���������� ���� ����� �˾ƾ� �Ѵ�. tellg()

int main() {
	ifstream fin("c://windows//system.ini", ios::in | ios::binary);
	ofstream fout("c://Temp//system.txt", ios::out | ios::binary);

	if (!fin || !fout) {
		cout << "���� ���� ���� !!" << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();

	int ch;
	for (int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize - i - 1, ios::beg);
		ch = fin.get();
		fout.put(ch); // binary�� << �ȵȴ�. 
	}

}