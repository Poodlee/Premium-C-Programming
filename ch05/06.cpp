#include <iostream>
#include <string>
using namespace std;

char& find(char a[], char c, bool& success) {  //���� c�� �ִ� ������ ���� ������ �����Ѵ�. ���� ���� �Լ�
	for (int i = 0; i < sizeof(a); i++) {  // char ->sizeof, string ->size
		if (*(a + i) == c) {
			success = true;
			return a[i];
		}
	}
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����. " << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}