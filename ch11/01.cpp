#include <iostream>
using namespace std;

int main() {
	int ch, cnt = 0; //ch: ���� �Ǹ� -1 ��ȯ�ϴϱ� int
	while ((ch = cin.get()) != EOF) {
		if (ch == '\n') break;
		if (ch == 'a') cnt++;
	}
	cout << "a�� ������ " << cnt << endl;
}