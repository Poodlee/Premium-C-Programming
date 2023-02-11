#include <iostream>
using namespace std;

void gugudan() {
	while (1) {
		int n;
		cout << "양수 입력 >> ";
		cin >> n;
		if (cin.fail())
			throw "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다.";
		if (n < 1 || n >9)
			throw "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요.";
		cout << n << "X1=" << n * 1 << " " << n << "X2=" << n * 2 << " " << n << "X3=" << n * 3 << " " << n << "X4=" << n * 4 << " "
			<< n << "X5=" << n * 5 << " " << n << "X6=" << n * 6 << " " << n << "X7=" << n * 7 << " " << n << "X8=" << n * 8 << " " << n << "X9=" << n * 9 << " " << endl;
	}
}

int main() {
	try {
		gugudan();
	}
	catch (const char* s) {
		cout << s << endl;
	}
}
