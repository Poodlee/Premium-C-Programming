#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\Temp\\test_05.txt", ios::in);

	if (!fin) {
		cout << "���� ���� ����!!" << endl;
		return 0;
	}
	int ch;
	while ((ch = fin.get()) != EOF) { // �ּ����̴ϱ� //�� ������ ���Ͱ� ���� �� ������ ��� �Է��� ���ָ� �ǰڴ�.
		if (ch == '/') {
			if ((ch = fin.get()) == '/') {
				fin.ignore(50, '\n');	// ���Ͱ� ���ö����� �� ����
				cout << endl;
			}
			else { //'/'�� �ϳ� ������ �׳� ����
				cout << '/';
			}
		}
		else cout.put(ch);
	}
}