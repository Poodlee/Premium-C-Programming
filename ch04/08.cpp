#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int radius,num;
	cout << "���� ���� :";
	cin >> num;
	Circle *p = new Circle [num];


	for (int i = 0; i < num; i++) {
		cout << "��" << i + 1 << " �� ������ >>";
		cin >> radius;
		p[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < num; i++) {
		if (p[i].getArea() > 100)
			count++;
	}
	cout << "������ 100���� ū ���� ������ " << count << "�� �̴�." << endl;
}