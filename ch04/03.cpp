#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string writing;
	cout << "���ڿ� �Է�>> ";
	getline(cin, writing, '\n');

	int count = 0;
	for (int i = 0; i < writing.size(); i++) {
		if (writing.at(i) == 'a') {
			count++;
		}
	}
	cout << "���� a�� " << count << "�� �ֽ��ϴ�." << endl;

	int index = 0;
	cout << "a�� �ε���: ";
	while ((index = writing.find('a', index)) != -1) {
		cout << index << ' ';
		index++;
	}

	return 0;
}