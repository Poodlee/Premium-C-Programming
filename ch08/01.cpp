#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius = 0, string name = "") : Circle(radius) {
		this->name = name; //radius 값 넣어야 하니까
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << name << endl;
	}
};


int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
}