#include <iostream>

int sum(int a, int b); // 함수 원형 선언, 장소 규약 X

int main() {

	int end = 0;

	std::cout << "끝 수를 입력하세요 >>";
	std::cin >> end;

	std::cout << "1에서" << end << "까지의 합은 " << sum(1,end) << "입니다.\n";
	return 0;
}

int sum(int a, int b) {
	int k, res = 0;
	for (int k = a; k <= b; k++) res += k;
	
	return res;
}