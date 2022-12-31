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
    b = tmp; //���� ���� (������ ��� ���� X)
}

int main() {
    Circle x(10);
    cout << "x�� ���� " << x.getArea() << endl;
    Circle y(20);
    cout << "y�� ���� " << y.getArea() << endl;

    cout << endl;

    swap(x, y);
    cout << "x�� ���� " << x.getArea() << endl;
    cout << "y�� ���� " << y.getArea() << endl;
}