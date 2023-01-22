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
	void setPoint(int x, int y) { // this->x = x; this->y = y; access 불가
		move(x, y);
	}
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
	}
};

int main() {
	ColorPoint zeroPoint; // BLACK 색에 (0,0) 위치의 점
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();
}