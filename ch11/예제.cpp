#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char cmd[80];
	cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
	while (1) {
		cout << "종료하려면 '우리 끝내자'를 입력하세요 >> ";
		cin.get(cmd, 80);
		if (strcmp(cmd, "우리 끝내자") == 0) {
			cout << "프로그램을 종료합니다...";
			return 0;
		}
		else 
			cin.ignore(1);
	}
}