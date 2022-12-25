#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name, this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager() { delete[]p; }
	void searchByName();
	void searchByArea();
};

CircleManager::CircleManager(int size) {
	this->size = size;
	p = new Circle[size];
	string name;
	int radius;
	for (int i = 0; i < size; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> name >> radius;
		p[i].setCircle(name,radius);
	}
}

void CircleManager::searchByName() {
	string name;
	int index = -1;

	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (p[i].getName() == name) {
			index = i;
		}
	}
	cout << p[index].getName() << "�� ������ " << p[index].getArea() << endl;
}

void CircleManager::searchByArea() {
	int area;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> area;
	cout << area << "���� ū ���� �˻��մϴ�.\n";
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() >= area) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
		}
	}
}

int main() {
	int size;
	cout << "���� ���� >> ";
	cin >> size;
	CircleManager DongJun(size);
	DongJun.searchByName();
	DongJun.searchByArea();
}