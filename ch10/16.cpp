#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() {	draw();	}
};
class Circle : public Shape {
	void draw() { cout << "Circle" << endl;  }
};
class Rect : public Shape {
	void draw() { cout << "Rectangle" << endl; }
};
class Line : public Shape {
	void draw() {	cout << "Line" << endl; }
};

class Program {
	vector<Shape*> v;
	void insert() {
		int choice;
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> choice;
		switch (choice) {
		case 1: v.push_back(new Line()); break;
		case 2: v.push_back(new Circle()); break;
		case 3: v.push_back(new Rect()); break;
		}
	}
	void erase() {
		int index;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
		cin >> index;
		v.erase(v.begin() + index);
	}
	void allSee() {
		for (int i = 0; i < v.size(); i++) {
			cout << i << ":  ";
			v[i]->paint();
		}
	}

public:
	void run() {
		cout << "�׷��� �������Դϴ�." << endl;
		while (1) {
			int choice;
			cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
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