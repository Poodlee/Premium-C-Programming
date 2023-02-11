#include <iostream>
using namespace std;

int sum(int a, int b);

int main() {
	try {
		cout << sum(2, 5) << endl;
		cout << sum(-1, 5) << endl;
		cout << sum(5, 2) << endl;	// 오류가 나면 이게 실행 X
	}
	catch (char* s) {
		cout << s << endl;
	}
}

int sum(int a, int b) {
	int result=0;
	char str[] = "잘못된 입력";
	char str1[] = "음수 처리 안 됨";
	if (a > b)
		throw str;
	if (a < 0 || b < 0)
		throw str1;

	for (int i = a; i <=b; i++)
		result += i;
	return result;
}