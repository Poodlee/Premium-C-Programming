#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string lyrics;
public:
	Histogram(string s) { lyrics = s; }
	Histogram& operator << (string s) {
		lyrics += s;
		return *this;
	}
	Histogram& operator << (char c) {
		lyrics += c;
		return *this;
	}
	void operator !() {
		int count = 0;
		int cnt[26] = { 0 };
		int length = lyrics.length(); // string : length(), char:strlen()

		cout << lyrics << endl << endl;

		for (int i = 0; i < length; i++) {
			lyrics [i] = tolower(lyrics[i]); // to calculate the number of alphabet. just change Capital to small 
		}
		// the number of each alphabet 
		for (int i = 0; i < length; i++) {
			if (lyrics[i] != 0) {
				for (int j = 0; j < 26; j++) {
					if (lyrics[i] == j + 'a') {  // int 97 = char 'a', by ASCII Code 
						cnt[j]++;
					}
				}
			}
		}
		// the total number of alphabets & print
		for (int i = 0; i < 26; i++) {
			cout << (char)(i + 'a') << ": "; // 만일 0인 것 표시안하려면 여기다 if문 추가.
			for (int j = 0; j < cnt[i]; j++) {
				count += cnt[j];
				cout << "*";
			}
			cout << "\n";
		}
		cout << "알파벳 총 개수 : " << count;
	}
};

int main() {
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "- by ";
	song << 'k' << 'i' << 't';
	!song;
}