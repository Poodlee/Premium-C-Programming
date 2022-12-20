#include <iostream>
#include <random>
using namespace std;

class Random {
public:
	int next();
	int nextInRange(int min, int max);
};

int Random::next() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 32237);
	return dis(gen);
}
int Random::nextInRange(int min, int max) {
	// 위와 같이 rand로 만들지만 min과 max 사이로 들어오게 만들면 충분하다.
	// 마치 Min-Max Data Wrangling 처럼 -> 나머지 + 최솟값
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	return dis(gen);
}

int main() {
	Random r;
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