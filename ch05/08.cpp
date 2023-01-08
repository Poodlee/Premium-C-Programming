#include <iostream>
#include <string>
using namespace std;

class MyIntStack { //Stack Ŭ����
	int* p; // ���� �޸𸮷� ����� ������
	int size;  // ������ �ִ� ũ��
	int tos;  // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack() { tos = -1; size = 1; p = new int[size];}
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack() { delete[] p; }
	bool push(int n); //���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����, ������ ��� ������ false, �ƴϸ� true ����

};
MyIntStack::MyIntStack(int size) {
	this->p = new int[size];
	this->size = size;
	this->tos = -1;
}
MyIntStack::MyIntStack(const MyIntStack& s) {
	int len = s.size;
	this->p = new int[len];
	this->size = len;
	this->tos = s.tos;

	for (int i = 0; i <= tos; i++) {
		this->p[i] = s.p[i];
	}
}
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
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //���� ����
	b.push(30);

	int n;
	a.pop(n);
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);
	cout << "���� b���� ���� �� " << n << endl;
}