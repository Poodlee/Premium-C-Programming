#include <iostream>
#include <cstdlib>	// rand()
#include <ctime>	//srand()
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int min, int max);
	int select;
};

int Random::next() {
	if (select == 0) {
		srand((unsigned)time(NULL)); // -> 출력 동일 왜?
		int n;
		do {
			n = rand();
		} while (n % 2 == 1);
		return n;
	}
	else if (select == 1) {
		srand((unsigned)time(NULL)); // -> 출력 동일 왜?
		int n;
		do {
			n = rand();
		} while (n % 2 == 0);
		return n;
	}
	else { cout << "잘못된 일력입니다." << endl; }

}
int Random::nextInRange(int min, int max) {
	if (select == 0) {
		srand((unsigned)time(0));
		int n;
		do {
			n = rand();
		} while (n % 2 == 1);
		n = n % (max - min + 1) + min;
		return n;
	}
	else if (select == 1) {
		srand((unsigned)time(0));
		int n;
		do {
			n = rand();
		} while (n % 2 == 0);
		n = n % (max - min + 1) + min;
		return n;
	}
	else { cout << "잘못된 일력입니다." << endl; }
	
}

int main() {
	Random r;
	cout << "홀수는 1 짝수는 0으로 입력해주세요.";
	int select;
	cin >> select;
	r.select = select;

	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 " << "4 까지의랜덤 정수 10개 -- " << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}