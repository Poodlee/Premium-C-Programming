#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in);
	ofstream fout("c:\\Temp\\sytstem.txt", ios::out);
	if (!fin || !fout) {
		cout << "파일 열기 실패!!" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF)
		fout << (char)toupper(ch); // 텍스트 I/O니까 << 사용 가능
	fin.close();
	fout.close();
}