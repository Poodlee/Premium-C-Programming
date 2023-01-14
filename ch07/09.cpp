#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " �� ��" << endl; }
	
	friend Circle operator +(int op2, Circle c);
	
	// �տ� Ŭ������ �ƴ϶� ���ڰ� �ͼ� ��������.
	/*
	Circle operator + (int op2) {
		Circle tmp; 
		tmp.radius = op2 + this->radius;
		return tmp;
	}
	*/
};

Circle operator +(int op2, Circle c) {
	Circle tmp;
	tmp.radius = op2 + c.radius;
	return tmp;
}


int main() {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}