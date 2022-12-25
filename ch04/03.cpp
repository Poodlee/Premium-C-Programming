#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string writing;
	cout << "문자열 입력>> ";
	getline(cin, writing, '\n');

	int count = 0;
	for (int i = 0; i < writing.size(); i++) {
		if (writing.at(i) == 'a') {
			count++;
		}
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;

	int index = 0;
	cout << "a의 인덱스: ";
	while ((index = writing.find('a', index)) != -1) {
		cout << index << ' ';
		index++;
	}

	return 0;
}