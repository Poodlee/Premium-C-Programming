#include <iostream>
#include <cstring>

using namespace std;

int main() {

	string menu;
	int total_income =0, number = 0;

	cout << "���������� 2000��,  �Ƹ޸�ī�� 2300��,  īǪġ�� 2500���Դϴ�.\n";

	while (true) {
		if (total_income <= 20000) {
			cout << "�ֹ� >>";
			cin >> menu >> number;
			if (menu == "����������") {
				cout << number * 2000 << "���Դϴ�. ���ְ� �弼��.\n";
				total_income += number * 2000;
			}
			if (menu == "�Ƹ޸�ī��") {
				cout << number * 2300 << "���Դϴ�. ���ְ� �弼��. \n";
				total_income += number * 2300;
			}
			if (menu == "īǪġ��") {
				cout << number * 2500 << "���Դϴ�. ���ְ� �弼��. \n";
				total_income += number * 2500;
			}
		}
		else {
			cout << "���� " << total_income << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�.  ���� ����~~~";
			break;
		}
	}

}
