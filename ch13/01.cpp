#include <iostream>
using namespace std;

int sum(int a, int b);

int main() {
	try {
		cout << sum(2, 5) << endl;
		cout << sum(-1, 5) << endl;
		cout << sum(5, 2) << endl;	// ������ ���� �̰� ���� X
	}
	catch (char* s) {
		cout << s << endl;
	}
}

int sum(int a, int b) {
	int result=0;
	char str[] = "�߸��� �Է�";
	char str1[] = "���� ó�� �� ��";
	if (a > b)
		throw str;
	if (a < 0 || b < 0)
		throw str1;

	for (int i = a; i <=b; i++)
		result += i;
	return result;
}