#include <iostream>
using namespace std;

int main() {

	int menu=0, number=0;

	cout << "***** �¸��忡 ���� ���� ȯ���մϴ�. *****\n";
	
	while (true) {
		cout << "«��:1, ¥��:2, ������:3, ����:4 >>";
		cin >> menu;
		if (menu >= 1 && menu <= 3) {
			cout << "���κ�?";
			cin >> number;

			switch (menu) {	 // switch���� break�� �ʼ��̴�.
			case 1: cout << "«�� " << number << "�κ� ���Խ��ϴ�.\n"; break;
			case 2: cout << "¥�� " << number << "�κ� ���Խ��ϴ�.\n"; break;
			case 3: cout << "������ " << number << "�κ� ���Խ��ϴ�.\n"; break;
			}
		}
		else if (menu == 4) {
			cout << "���� ������ �������ϴ�.";
			break;
		}
		else cout << "�ٽ� �ֹ��ϼ���!!\n";
	}
	
}