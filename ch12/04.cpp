#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in);
	ofstream fout("c:\\Temp\\sytstem.txt", ios::out);
	if (!fin || !fout) {
		cout << "���� ���� ����!!" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF)
		fout << (char)toupper(ch); // �ؽ�Ʈ I/O�ϱ� << ��� ����
	fin.close();
	fout.close();
}