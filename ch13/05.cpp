#include <iostream>
using namespace std;

void gugudan() {
	while (1) {
		int n;
		cout << "��� �Է� >> ";
		cin >> n;
		if (cin.fail())
			throw "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�.";
		if (n < 1 || n >9)
			throw "�߸��� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���.";
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
