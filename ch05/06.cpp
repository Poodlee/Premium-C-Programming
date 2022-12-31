#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {  //문자 c가 있는 공간에 대한 참조를 리턴한다. 참조 리턴 함수
	for (int i = 0; i < sizeof(a); i++) {  // char ->sizeof, string ->size
		if (*(a + i) == c) {
			success = true;
			return a[i];
		}
	}
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다. " << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}