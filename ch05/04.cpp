#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b) { return true; }
	else if (a > b) { big = a; return false; }
	else { big = b; return false; }
}


int main() {
	int a, b, big;
	int c;
	cout << "���� �� ���� �ۼ����ּ���." << endl;
	cin >> a >> b;
	c = bigger(a, b, big);
	if (bigger(a, b, big)) { cout << "a�� b�� ����. ���� ū ���� a=b= " << a << endl; }
	else { cout << "a�� b�� �ٸ��� �� ū ���� ������ ����. " << big << endl; }
}