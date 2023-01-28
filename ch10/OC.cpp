#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Word {
	string en, ko;
public:
	Word(string en, string ko) {
		this->en = en; this->ko = ko;
	}
	string getEn() { return en; }
	string getKo() { return ko; }
};

int main() {
	vector<Word> v;
	v.push_back(Word("baby", "아기"));
	v.push_back(Word("human", "인간"));
	v.push_back(Word("society", "사회"));
	v.push_back(Word("photo", "사진"));
	v.push_back(Word("painting", "그림"));
	v.push_back(Word("Love", "사랑"));
	v.push_back(Word("dall", "인형"));
	v.push_back(Word("emotion", "감정"));
	v.push_back(Word("trade", "거래"));
	v.push_back(Word("animal", "동물"));
	v.push_back(Word("bear", "곰"));

	srand((unsigned)time(0));
	int n1; string answer;
	string bogi[4]; for (int i = 0; i < 4; i++) bogi[i] = "";
	int number[4]; for (int i = 0; i < 4; i++) number[i] = 0;
	int i;
	bool exit = true;

	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;
	while (exit) {
		n1 = rand() % v.size();
		bogi[0] = v.at(n1).getKo();
		answer = bogi[0];
		cout << v.at(n1).getEn() << "?" << endl;

		while (exit) {				// 중복되지 않는 보기 만들기
			for (i = 1; i < 4; i++) {
				n1 = rand() % v.size();
				bogi[i] = v.at(n1).getKo();
			}
			if (bogi[0] != bogi[1] && bogi[0] != bogi[2] && bogi[0] != bogi[3] &&
				bogi[1] != bogi[2] && bogi[1] != bogi[3] && bogi[2] != bogi[3])
				exit = false;
		}
		exit = true;

		number[0] = rand() % 4;
		while (exit) {					//보기 순서 섞기
			for (i = 1; i < 4; i++) {
				number[i] = rand() % 4;
			}
			if (number[0] != number[1] && number[0] != number[2] && number[0] != number[3] &&
				number[1] != number[2] && number[1] != number[3] && number[2] != number[3])
				exit = false;
		}
		exit = true;
		int result;

		for (i = 1; i < 5; i++)
			cout << "(" << i << ") " << bogi[number[i - 1]] << " ";
		cout << ":>";
		cin >> result;

		if (result != 1 && result != 2 && result != 3 && result != 4)	//순서 중요 먼저 1, 2, 3, 4 이외의 값인지 확인해야함
			exit = false;
		else if (answer == bogi[number[result - 1]])
			cout << "Excellent !!" << endl;
		else if (result == 1 || result == 2 || result == 3 || result == 4)
			cout << "No. !!" << endl;
	}
}