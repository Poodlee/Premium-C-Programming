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

		// �ϴ� �ҹ��� �����
		string lowerString;
		for (int i = 0; i < mainString.length(); i++) {
			lowerString += tolower(mainString[i]);
		}

		// ���� ����
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

		// ���
		cout << "�� ���ĺ� �� " << sum << endl;

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
	song << "falling" << " in love with you." << "- by "; // ������׷� ���ڿ� �߰�
	song << 'k' << 'i' << 't'; // ������׷� ���� �߰�
	!song; // ������׷� �׸���
}