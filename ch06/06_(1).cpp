#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	//s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* concat(int s1[], int s2[], int size);

	//s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하열 리턴
	//리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* sumArray = new int[size];
	for (int i = 0; i < size/2; i++) {
		sumArray[i] = s1[i];
		sumArray[i + size/2] = s2[i];
	}
	return sumArray;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int* tmp = new int[size];
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) { s1[i] = NULL; break; }
			if (j == size - 1) tmp[cnt++] = s1[i]; // 그냥 자체적으로 i 따라가니까 땡겨줘야 한다. 그래서 새로운 인자 추가
		}
	}
	if (cnt == 0) return NULL;
	retSize = cnt;
	int* ret = new int[retSize];
	
	// 앞으로 땡기는 걸 안 넣었네... 그래서 계속 잘못된 거임.
	for (int i = 0; i < retSize; i++) {
		ret[i] = tmp[i];
	}

	std::cout << "\n 중간 테스트 입니다.\n";
	for (int i = 0; i < size; i++) std::cout << s1[i] << ' ';
	std::cout << endl;
	for (int i = 0; i < retSize; i++) std::cout << tmp[i] << ' ';
	std::cout << endl << endl;

	return ret;
}

int main() {
	int x[5], y[5], retSize = 0, size;

	std::cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	std::cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	std::cout << "합친 정수 배열을 출력한다." << endl;

	size = 10; // x와 y 개수 합
	int* temp = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < size; i++) std::cout << temp[i] << ' ';
	std::cout << endl;

	size = 5; // x내에서 진행
	int* temp2 = ArrayUtility2::remove(x, y, size, retSize); // 참조 변수로 선언해서 이렇게 진행해도 충분
	std::cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) std::cout << temp2[i] << ' ';
	std::cout << endl;
}