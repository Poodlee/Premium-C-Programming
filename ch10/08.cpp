#include <iostream>
using namespace std;

class Comparable {
public: 
	virtual bool operator > (Comparable& op2) = 0;
	virtual bool operator < (Comparable& op2) = 0;
	virtual bool operator == (Comparable& op2) = 0;
};
class Circle : public Comparable
{
private:
	int radius;
public:
	Circle(int radius=0) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Comparable& op2) { 
		Circle* op = (Circle*)&op2; //op2를 circle로 변경 해줘야 한다.
		if (this->radius > op->radius) return true;
		else return false;
	}
	bool operator < (Comparable& op2) {
		Circle* op = (Circle*)&op2; //op2를 circle로 변경 해줘야 한다.
		if (this->radius < op->radius) return true;
		else return false;
	}
	bool operator == (Comparable& op2) {
		Circle* op = (Circle*)&op2; //op2를 circle로 변경 해줘야 한다.
		if (this->radius == op->radius) return true;
		else return false;
	}
};
template <typename T>
T bigger(T a, T b)
{
	if (a > b) return a;  // -> Circle class 들어왔을 때에 연산자 어떻게 할 지 
	// 연산자 중복
	else return b;
}
int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20과 50 중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;

	return 0;
}