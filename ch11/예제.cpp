#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char cmd[80];
	cout << "cin.get(char*, int)�� ���ڿ��� �н��ϴ�." << endl;
	while (1) {
		cout << "�����Ϸ��� '�츮 ������'�� �Է��ϼ��� >> ";
		cin.get(cmd, 80);
		if (strcmp(cmd, "�츮 ������") == 0) {
			cout << "���α׷��� �����մϴ�...";
			return 0;
		}
		else 
			cin.ignore(1);
	}
}