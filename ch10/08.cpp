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
		Circle* op = (Circle*)&op2; //op2�� circle�� ���� ����� �Ѵ�.
		if (this->radius > op->radius) return true;
		else return false;
	}
	bool operator < (Comparable& op2) {
		Circle* op = (Circle*)&op2; //op2�� circle�� ���� ����� �Ѵ�.
		if (this->radius < op->radius) return true;
		else return false;
	}
	bool operator == (Comparable& op2) {
		Circle* op = (Circle*)&op2; //op2�� circle�� ���� ����� �Ѵ�.
		if (this->radius == op->radius) return true;
		else return false;
	}
};
template <typename T>
T bigger(T a, T b)
{
	if (a > b) return a;  // -> Circle class ������ ���� ������ ��� �� �� 
	// ������ �ߺ�
	else return b;
}
int main()
{
	int a = 20, b = 50, c;
	c = bigger(a, b);
	cout << "20�� 50 �� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;

	return 0;
}