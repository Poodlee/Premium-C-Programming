#include <iostream>


int main() {
	
	int n=0 , sum = 0;
	

	std::cout << "�� ���� �Է��ϼ��� >>";
	std::cin >> n;
	for (int k = 0; k <= n; k++) {
		sum += k;
	}
	std::cout << "1����" << n << "������ ���� " << sum << "�Դϴ�.\n";
	return 0;
}