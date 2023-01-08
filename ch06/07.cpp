#include <iostream>
#include <string>
#include <random>
using namespace std;

class Random {
public:
	static void seed() {}
	static int nextInt(int min = 0, int max = 32767) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(min, max);
		return dis(gen);
	}
	static char nextAlphabet();
	static double nextDouble();
};
char Random::nextAlphabet() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 1);
	if (dis(gen) == 0) {
		int n;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 25);
		n = 65 + dis(gen);
		return n;
	}
	else {
		int n = 0;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 25);
		n = 97 + dis(gen);
		return n;
	}
}
double Random::nextDouble() {
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(0,1);

	return dis(gen);
}

int main() {
	Random::seed();		//static 멤버 함수 실행
	int i;

	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다" << endl;
	for (i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';

	cout << endl << "알파벳을 랜덤하게 10개를 출력합니다" << endl;
	for (i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';

	cout << endl << "랜덤한 실수를 10개를 출력합니다" << endl;
	for (i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;
	for (i = 0; i < 5; i++) cout << Random::nextDouble() << ' ';
	cout << endl;

}