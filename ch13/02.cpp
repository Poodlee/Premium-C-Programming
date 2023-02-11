#include <iostream>
using namespace std;

int main() {
	int score;
	while (1) {
		try {
			cout << "점수를 입력하세요 : ";
			cin >> score;
			if (score > 100)
				throw score;
			if (score >= 90) {
				cout << "체점 결과 " << score << "점으로 A 학점입니다." << endl;
			}
			else if (score >= 80)
				cout << "체점 결과 " << score << "점으로 B 학점입니다." << endl;
			else if (score >= 70)
				cout << "체점 결과 " << score << "점으로 C 학점입니다." << endl;
			else if (score >= 60)
				cout << "체점 결과 " << score << "점으로 D 학점입니다." << endl;
			else
				cout << "체점 결과 " << score << "점으로 F 학점입니다." << endl;
		}

		catch (int t) {
			cout << "옳지 않은 점수입니다. (" << t << "점). " << endl;
		}
	}
}