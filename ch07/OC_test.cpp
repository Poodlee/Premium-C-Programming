#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string mainString;
public:
	Histogram(string inputSting) {
		mainString = inputSting;
	}
	Histogram& operator << (string s) {
		this->mainString += s;
		return *this;
	}
	Histogram& operator << (char c) {
		this->mainString += c;
		return *this;
	}
	void operator ! () {
		cout << mainString << endl << endl;

		// 싹다 소문자 만들기
		string lowerString;
		for (int i = 0; i < mainString.length(); i++) {
			lowerString += tolower(mainString[i]);
		}

		// 숫자 세기
		int sum = 0;
		string index = "abcdefghijklmnopqrstuvwxyz";
		int indexNum[26];
		for (int i = 0; i < 26; i++) {
			int count = 0;
			for (int j = 0; j < lowerString.length(); j++) {
				if (index[i] == lowerString[j]) {
					count = count + 1;
					sum = sum + 1;
				}
			}
			indexNum[i] = count;
		}

		// 출력
		cout << "총 알파벳 수 " << sum << endl;

		for (int i = 0; i < 26; i++) {
			cout << index[i] << ":";
			for (int j = 0; j < indexNum[i]; j++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by "; // 히스토그램 문자열 추가
	song << 'k' << 'i' << 't'; // 히스토그램 문자 추가
	!song; // 히스토그램 그리기
}