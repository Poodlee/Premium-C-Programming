#include <iostream>
using namespace std;
class Circle
{
private:
	int radius;
public:
	Circle() { this->radius = 0; }
	Circle(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Circle& ref) { return this->radius > ref.radius; }
	bool operator < (Circle& ref) { return this->radius < ref.radius; }
	bool operator == (Circle& ref) { return this->radius == ref.radius; }
};
template <class T>
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