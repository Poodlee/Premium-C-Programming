#include <iostream>

int sum(int a, int b); // �Լ� ���� ����, ��� �Ծ� X

int main() {

	int end = 0;

	std::cout << "�� ���� �Է��ϼ��� >>";
	std::cin >> end;

	std::cout << "1����" << end << "������ ���� " << sum(1,end) << "�Դϴ�.\n";
	return 0;
}

int sum(int a, int b) {
	int k, res = 0;
	for (int k = a; k <= b; k++) res += k;
	
	return res;
}