#include <iostream>
#include <string>
using namespace std;

class MyIntStack { //Stack Ŭ����
	int p[10];  // �ִ� 10���� ���� ����
	int tos;  // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() { tos = -1; }
	bool push(int n); //���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����, ������ ��� ������ false, �ƴϸ� true ����

};
bool MyIntStack::push(int n) {
	if (tos >= 9) { return false; }
	p[++tos] = n;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos < 0) { return false; }
	n = p[tos--];
	return true;
}


int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}