#include <iostream>
using namespace std;

class Circle {
    int r;
public:
    Circle() { this->r = 1; }
    Circle(int r) { this->r = r; }
    double getArea() {return this->r * this->r * 3.14; }

};

void swap(Circle& a, Circle& b) {
    Circle tmp = a;
    a = b;
    b = tmp; //얕은 복사 (포인터 멤버 변수 X)
}

int main() {
    Circle x(10);
    cout << "x의 넓이 " << x.getArea() << endl;
    Circle y(20);
    cout << "y의 넓이 " << y.getArea() << endl;

    cout << endl;

    swap(x, y);
    cout << "x의 넓이 " << x.getArea() << endl;
    cout << "y의 넓이 " << y.getArea() << endl;
}