#include <iostream>
#include <cmath> // cos, sin 함수 이용하기 위해서
using namespace std;

#define PI 3.141592

void polar_to_cartesian(double& a, double& b) {
	double temp_a, temp_b;
	temp_a = a;
	temp_b = b;
	a = temp_a * cos(temp_b * PI / 180);
	b = temp_a * sin(temp_b * PI / 180);
}

int main() {
	cout << "반지름과 각도(degree)를 입력하면 각각 x좌표와 y좌표로 변환해주는 장치입니다. 삐빅!!" << endl;
	cout << "반지름과 각도를 입력해 주세요.";
	double a, b;
	cin >> a >> b;
	polar_to_cartesian(a, b);

	cout << fixed; // 소수점 아래 몇 자리 가져올 지 정할래!
	cout.precision(2); // 소수점 아래 2자리만 보겠슴.(반올림)

	cout << "x 좌표는 " << a << " y 좌표는 " << b << " 입니다." << endl;
}