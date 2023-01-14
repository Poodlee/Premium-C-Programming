#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
	int m[2][2];
public:
	Matrix(int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0) {
		m[0][0] = m1;
		m[0][1] = m2;
		m[1][0] = m3;
		m[1][1] = m4;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				cout << m[i][j] << ' ';
		cout << "}" << endl;
	}
	//6-1
	/*
	Matrix operator +(Matrix op2) {
		Matrix tmp; // 원래 있던 것들 안 바뀌고 나가야지
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				tmp.m[i][j] = m[i][j] + op2.m[i][j];
		return tmp;
	}
	Matrix& operator += (Matrix op2) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				m[i][j] += op2.m[i][j];
		return *this;
	}
	bool operator == (Matrix op2) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				if (m[i][j] != op2.m[i][j]) return false;
		return true;
	}
	*/
	//6-2
	friend Matrix operator +(Matrix op1, Matrix op2);
	friend Matrix& operator += (Matrix& op1, Matrix op2);
	friend bool operator == (Matrix op1, Matrix op2);
};
Matrix operator +(Matrix op1, Matrix op2) {
	Matrix tmp;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			tmp.m[i][j] = op1.m[i][j] + op2.m[i][j];
	return tmp;
}
Matrix& operator += (Matrix& op1, Matrix op2) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			op1.m[i][j] += op2.m[i][j];
	return op1;
}
bool operator == (Matrix op1, Matrix op2) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (op1.m[i][j] != op2.m[i][j]) return false;
	return true;
}
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and C are the same" << endl;
}