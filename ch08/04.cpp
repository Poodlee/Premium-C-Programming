#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};
class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x=0, int y=0, string color="BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { // this->x = x; this->y = y; access �Ұ�
		move(x, y);
	}
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK ���� (0,0) ��ġ�� ��
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}