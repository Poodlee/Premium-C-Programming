#include <iostream>
using namespace std;

/*
int* copy(int* src, int size, int& failCode) {
	int* p = NULL;
	if (size < 0) {
		failCode = -1;
		return NULL;
	}
	else if (size > 100) {
		failCode = -2;
		return NULL;
	}
	p = new int[size];
	if (p == NULL) {
		failCode = -3;
		return NULL;
	}
	else if (src == NULL) {
		failCode = -4;
		delete[] p;
		return NULL;
	}
	else {	// ������ ����
		for (int n = 0; n < size; n++)	p[n] = src[n];
		failCode = 0;
		return p;
	}
}
*/

int* copy(int* src, int size) throw(char*){
	if (size < 0) {
		throw "size�� �����Դϴ�.";
	}
	else if (size > 100) {
		throw "Size�� �ʹ� Ů�ϴ�.";
	}
	int* p = NULL;
	p = new int[size];
	if (p == NULL) {
		throw "memory short";
	}
	else if (src == NULL) {
		throw "NULL score";
		delete[] p;
	}
	else {	// ������ ����
		for (int n = 0; n < size; n++)	p[n] = src[n];
		return p;
	}
}

int main() {
	int x[] = { 1,2,3 };
	try {
		int* p = copy(x, -1);
		for (int i = 0; i < 3; i++)	cout << p[i] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (const char* s) {
		cout << "���� �ڵ� : " << s << endl;
	}
}