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
		cout << "원" << i + 1 << " 의 반지름 >>";
		cin >> radius;
		CircleArrays[i].setRadius(radius);
	}
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (CircleArrays[i].getArea() > 100)
			count++;
	}
	cout << "면적이 100보다 큰 원의 개수는 " << count << "개 이다." << endl;
}