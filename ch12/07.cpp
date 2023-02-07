#include <iostream>
#include <fstream>
using namespace std;
// 뒤집으려면 파일 사이즈를 알아야 한다. tellg()

int main() {
	ifstream fin("c://windows//system.ini", ios::in | ios::binary);
	ofstream fout("c://Temp//system.txt", ios::out | ios::binary);

	if (!fin || !fout) {
		cout << "파일 열기 오류 !!" << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();

	int ch;
	for (int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize - i - 1, ios::beg);
		ch = fin.get();
		fout.put(ch); // binary라서 << 안된다. 
	}

}