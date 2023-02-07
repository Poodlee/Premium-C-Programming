#include<iostream>
#include<fstream>

using namespace std;
int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if (!fin) {
		cout << "c:\\windows\\system.ini 열기 오류" << endl;
	}
	// gcount 이용 + 계속해서 문자 읽기 + 크기 정확히 알기 위해 binary모드
	char ch[32] = { 0 };
	int cnt = 0;
	while (!fin.eof()) {
		fin.read(ch, 32);
		int n = fin.gcount();
		cnt += n;
	}
	cout << "파일의 크기는 " << cnt << " 입니다." << endl;
}