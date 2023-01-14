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
		cout << "\nend-point�� ��ǥ�� ������ �����ϴ�." << endl;
		cout << "x ��ǥ: " << Motor::cord_x << " y ��ǥ: " << Motor::cord_y;
	}
};
double Motor::cord_x = 0;
double Motor::cord_y = 0;

int main() {
	cout << "�ȳ��ϼ���. ���� 2���� ������ end-point�� ��ǥ�� �˾� ���� ��ġ�Դϴ�. " << endl;
	cout << "���� 2���� ���� �������� �Է��� �ּ���.";
	double radius1, radius2;
	cin >> radius1 >> radius2;
	cout << endl;

	Motor motor1(radius1);
	Motor motor2(radius2);

	while (true) {
		cout << "\n�̵��Ͻ� motor�� ������ �ּ���. " << endl;
		cout << " 1��.motor1  2��.motor2 3��.�Ѵ�\n";
		int select;
		double angle1, angle2;
		cin >> select;
		switch (select) {
		case 1:
			cout << "motor1�� �� �� �����ڽ��ϱ�? ";
			cin >> angle1;
			motor1.move(angle1);
			motor1.show();
			break;
		case 2:
			cout << "\nmotor2�� �� �� �����ڽ��ϱ�? ";
			cin >> angle2;
			motor2.move(angle2);
			motor2.show();
			break;
		case 3:
			cout << "\nmotor1, motor2 ���� �� �� �����ڽ��ϱ�?";
			cin >> angle1 >> angle2;
			motor1.move(angle1);
			motor2.move(angle2);
			motor2.show();
			break;
		}
	}
}