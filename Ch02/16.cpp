#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// alphabet (Ascii) a-z : 97-122, A-Z : 65-90
int main() {

	char text[10001];
	int count = 0;
	int cnt[26] = { 0 };

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n" << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
	cout << "-----------------------------------------------------------\n\n";
	cin.getline(text, 10000, ';');

	int length = strlen(text);
	
	for (int i = 0; i < length; i++){
		text[i] = tolower(text[i]); // to calculate the number of alphabet. just change Capital to small 
	}
	// the number of each alphabet 
	for (int i = 0; i < length; i++) {
		if (text[i] != 0) {
			for (int j = 0; j < 26; j++) {
				if (text[i] == j + 'a') {  // int 65 = char 'A', by ASCII Code 
					cnt[j]++;
				}
			}
		}
	}
	// the total number of alphabets & print
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) {
			cout << (char)(i + 'a') << "  (" << cnt[i] << ")" << "   :  ";
			for (int j = 0; j < cnt[i]; j++) {
				count += cnt[j];
				cout << "*";
			}
			cout << "\n";
		}
	}
	cout << "알파벳 총 개수 : " << count;

}
