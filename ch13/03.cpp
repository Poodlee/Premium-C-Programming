#include <iostream>
using namespace std;

void get(int n1, int n2) throw(char*);

int main() {
	int num1, num2;
	bool exit;
	while (1) {
		int result;
		try {
			cout << "0~9 ������ ���� �Է� >> ";
			cin >> num1;
			cout << "0~9 ������ ���� �Է� >> ";
			cin >> num2;
			get(num1, num2);
		}
		catch (char* s) {
			cout << s << endl;
		}
	}
}

void get(int n1, int n2) throw(char*) {
	int result;
	char str[] = "input fault ���� �߻�, ����� �� ����";
	if (n1 < 0 || n2 < 0) throw str;
	result = n1 * n2;
	cout << n1 << "X" << n2 << "=" << result << endl;
}