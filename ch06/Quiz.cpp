#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.141592

class Motor {
private:
	double radius;
public:
	static double cord_x, cord_y;
	Motor(double radius) {
		this->radius = radius;
	}
	void move(double angle) {
		double temp_a, temp_b;
		temp_a = radius;
		temp_b = angle;
		Motor::cord_x = Motor::cord_x + temp_a * cos(temp_b * PI / 180);
		Motor::cord_y = Motor::cord_y + temp_a * sin(temp_b * PI / 180);
	}
	void show() {
		cout << "\nend-point의 좌표는 다음과 같습니다." << endl;
		cout << "x 좌표: " << Motor::cord_x << " y 좌표: " << Motor::cord_y;
	}
};
double Motor::cord_x = 0;
double Motor::cord_y = 0;

int main() {
	cout << "안녕하세요. 모터 2개를 움직여 end-point의 좌표를 알아 보는 장치입니다. " << endl;
	cout << "모터 2개의 각각 반지름을 입력해 주세요.";
	double radius1, radius2;
	cin >> radius1 >> radius2;
	cout << endl;

	Motor motor1(radius1);
	Motor motor2(radius2);

	while (true) {
		cout << "\n이동하실 motor를 선택해 주세요. " << endl;
		cout << " 1번.motor1  2번.motor2 3번.둘다\n";
		int select;
		double angle1, angle2;
		cin >> select;
		switch (select) {
		case 1:
			cout << "motor1을 몇 도 돌리겠습니까? ";
			cin >> angle1;
			motor1.move(angle1);
			motor1.show();
			break;
		case 2:
			cout << "\nmotor2을 몇 도 돌리겠습니까? ";
			cin >> angle2;
			motor2.move(angle2);
			motor2.show();
			break;
		case 3:
			cout << "\nmotor1, motor2 각각 몇 도 돌리겠습니까?";
			cin >> angle1 >> angle2;
			motor1.move(angle1);
			motor2.move(angle2);
			motor2.show();
			break;
		}
	}
}