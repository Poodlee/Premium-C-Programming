#include <iostream>

int main() {
	int* pArray = new int[5];
	double sum = 0;
	std::cout << "정수 5개 입력";
	for (int i = 0; i < 5; i++) {
		int value;
		std::cin >> pArray[i];
		sum += pArray[i];
	}
	std::cout << "평균 " << sum / 5;
	delete[] pArray;
}