#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
	friend Circle operator +(int op2, Circle c);

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