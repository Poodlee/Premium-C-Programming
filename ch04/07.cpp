#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int radius;
	Circle CircleArrays[3];

	for (int i = 0; i < 3; i++) {
		cout << "��" << i + 1 << " �� ������ >>";
		cin >> radius;
		CircleArrays[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (CircleArrays[i].getArea() > 100)
			count++;
	}
	cout << "������ 100���� ū ���� ������ " << count << "�� �̴�." << endl;
}