#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\Temp\\test_05.txt", ios::in);

	if (!fin) {
		cout << "파일 열기 실패!!" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF) { // 주석문이니까 //가 나오면 엔터가 나올 떄 까지의 모든 입력은 없애면 되겠다.
		if (ch == '/') {
			if ((ch = fin.get()) == '/') {
				fin.ignore(50, '\n');	// 엔터가 나올때까지 다 무시
				cout << endl;
			}
			else { //'/'가 하나 나오면 그냥 진행
				cout << '/';
			}
		}
		else cout.put(ch);
	}
}