#include <iostream>
using namespace std;

class MyIntStack { //Stack 클래스
	int p[10];  // 최대 10개의 정수 저장
	int tos;  // 스택의 꼭대기를 가리키는 인덱스
public:
	MyIntStack() { tos = -1; }
	bool push(int n); //정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
	bool pop(int& n); // 팝하여 n에 저장, 스택이 비어 있으면 false, 아니면 true 리턴

};
bool MyIntStack::push(int n) {
	if (tos >= 9) { return false; }
	p[++tos] = n;
	return true;
}

bool MyIntStack::pop(int& n) {
	if (tos < 0) { return false; }
	n = p[tos--];
	return true;
}

class ArrayUtility2 {
public:
	//s1과 s2를 연결한 새로운 배열을 동적 생성하고 포인터 리턴
	static int* concat(int s1[], int s2[], int size);

	//s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하열 리턴
	//리턴하는 배열의 크기는 retSize에 전달. retSize가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	int* sumArray = new int[size * 2];
	for (int i = 0; i < size; i++) {
		sumArray[i] = s1[i];
	}
	for (int i = 0; i < size; i++) {
		sumArray[i + size] = s2[i];
	}
	return sumArray;
}
int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) s1[i] = NULL;
		}
	}
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) retSize++;
	}
	if (retSize == 0) return NULL;
	int* p = new int[retSize];
	// 이제 동일하지 않은 부분 찾기 + 배열에서 성분 추가 안되니까
	// stack 이용해서 push하고 해당 값들 또 새롭게 p에 할당 해주면 되겠지?
	MyIntStack stack;
	int *p_inverse = new int[retSize];
	for (int i = 0; i < size; i++) {
		if (s1[i] != NULL) stack.push(s1[i]);
	}
	for (int i = 0; i < retSize; i++) {
		stack.pop(p_inverse[i]);
	}
	for (int i = 0; i < retSize; i++) {
		p[i] = p_inverse[retSize - i];
	}
	return p;
}

int main() {
	int x[5], y[5], retSize = 0, size;

	cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";
	cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
	cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";
	cin >> y[0] >> y[1] >> y[2] >> y[3] >> y[4];
	cout << "합친 정수 배열을 출력한다." << endl;

	size = 10; // x와 y 개수 합
	int* temp = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < size; i++) cout << temp[i] << ' ';
	cout << endl;
	
	size = 5; // x내에서 진행
	int* temp2 = ArrayUtility2::remove(x, y, size, retSize); // 참조 변수로 선언해서 이렇게 진행해도 충분
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) cout << temp[i] << ' ';
	cout << endl;
}