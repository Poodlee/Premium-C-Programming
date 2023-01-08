#include <iostream>
#include <cmath> // cos, sin �Լ� �̿��ϱ� ���ؼ�
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
	cout << "�������� ����(degree)�� �Է��ϸ� ���� x��ǥ�� y��ǥ�� ��ȯ���ִ� ��ġ�Դϴ�. �ߺ�!!" << endl;
	cout << "�������� ������ �Է��� �ּ���.";
	double a, b;
	cin >> a >> b;
	polar_to_cartesian(a, b);

	cout << fixed; // �Ҽ��� �Ʒ� �� �ڸ� ������ �� ���ҷ�!
	cout.precision(2); // �Ҽ��� �Ʒ� 2�ڸ��� ���ڽ�.(�ݿø�)

	cout << "x ��ǥ�� " << a << " y ��ǥ�� " << b << " �Դϴ�." << endl;
}