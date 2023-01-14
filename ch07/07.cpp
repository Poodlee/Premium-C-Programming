#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
	int m[4];
public:
	Matrix(int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0) {
		m[0] = m1;
		m[1] = m2;
		m[2] = m3;
		m[3] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++)
			cout << m[i] << ' ';
		cout << "}" << endl;
	}
	/*
	void operator >>(int op2[4]) {
		for (int i = 0; i < 4; i++)
			op2[i] = m[i];
	}
	Matrix& operator <<(int op2[4]) {
		for (int i = 0; i < 4; i++)
			m[i] = op2[i];
		return *this;
	}
	*/
	friend void operator >>(Matrix op1, int op2[4]);
	friend Matrix& operator << (Matrix &op1, int op2[4]);
};
void operator >>(Matrix op1, int op2[4]) {
	for (int i = 0; i < 4; i++)
		op2[i]=op1.m[i];
}
Matrix& operator <<(Matrix &op1, int op2[4]) {
	for (int i = 0; i < 4; i++)
		op1.m[i] = op2[i];
	return op1;
}

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' '; // x[]Ãâ·Â
	cout << endl;
	b.show();

	return 0;
}