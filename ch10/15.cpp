#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	Circle(int radius = 0, string name = "") {
		this->radius = radius; this->name = name;
	}
	int getRadius() { return radius; }
	string getName() { return name; }
};
class Program {
	vector < Circle> v;
	void insert() {
		int radius;
		string name;
		cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
		cin >> radius >> name;
		v.push_back(Circle(radius, name));
	}
	void erase() {
		string name;
		cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
		cin >> name;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].getName() == name)
				v.erase(v.begin() + i);
		}
	}
	void allSee() {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].getName() << endl;
		}
		cout << endl;
	}
public:
	void run() {
		int choice;
		cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�." << endl;
		while (1) {
			cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
			cin >> choice;
			switch (choice) {
			case 1: insert(); break;
			case 2: erase(); break;
			case 3: allSee(); break;
			case 4: return;
			}

		}
	}
};

int main() {
	Program DJ_Program;
	DJ_Program.run();
}