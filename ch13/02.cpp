#include <iostream>
using namespace std;

int main() {
	int score;
	while (1) {
		try {
			cout << "������ �Է��ϼ��� : ";
			cin >> score;
			if (score > 100)
				throw score;
			if (score >= 90) {
				cout << "ü�� ��� " << score << "������ A �����Դϴ�." << endl;
			}
			else if (score >= 80)
				cout << "ü�� ��� " << score << "������ B �����Դϴ�." << endl;
			else if (score >= 70)
				cout << "ü�� ��� " << score << "������ C �����Դϴ�." << endl;
			else if (score >= 60)
				cout << "ü�� ��� " << score << "������ D �����Դϴ�." << endl;
			else
				cout << "ü�� ��� " << score << "������ F �����Դϴ�." << endl;
		}

		catch (int t) {
			cout << "���� ���� �����Դϴ�. (" << t << "��). " << endl;
		}
	}
}