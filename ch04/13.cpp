#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string str;
public:
	Histogram(string str);
	void put(string str);
	void putc(char ch);
	void print();
};

Histogram::Histogram(string str) {
	this->str = str;
}

void Histogram::put(string str) {
	this->str += '\n' + str;
}

void Histogram::putc(char ch) {
	this->str += ch;
}

void Histogram::print() {
	cout << str << '\n' << endl;
	int length = str.size();
	int total_count = 0, cnt[26] = { 0 };

	for (int i = 0; i < length; i++) {
		str[i] = tolower(str[i]); // to calculate the number of alphabet. change Capital to small
	}

	// the number of each alphabet
	for (int i = 0; i < length; i++) {
		if (str[i] != 0) {
			for (int j = 0; j < 26; j++) {
				if (str[i] == j + 'a') {
					cnt[j]++;
				}
			}
		}
	}

	// the total number of alphabets alphabets & print
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 0) {
			cout << (char)(i + 'a') << " (" << cnt[i] << ")" << "   :   ";
			for (int j = 0; j < cnt[i]; j++) {
				cout << "*";
			}
			total_count += cnt[i];
			cout << "\n";
		}
	}
	cout << "¾ËÆÄºª ÃÑ °³¼ö : " << total_count;
}

int main(void) {

	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

	return 0;
}