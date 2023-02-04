#include <iostream>
#include <random>
using namespace std;

// ��ȭ ����
class item {
protected:
	int level,money;
public:
	int challenge;
	item() { level = 1; money = 1000; }
	void Upgrade();
	void Upgrade_success() { level += 1; money += 1000; }
	void Upgrade_fail() { if (level == 1) { level = 1; } else { level -= 1; money -= 1000; } }
	void Destroy() { level = 1; money = 1000; }
	int getLevel() { return level; }
	int getMoney() { return money; }
};
class Weapon : public item {
public:
	Weapon() : item() { ; }
	void Upgrade(int level) { // ������ ������ ���� ����Ȯ�� (80->70->60...) ���� Ȯ��(10->20->30...) ���� Ȯ��(10) �ִ� 5������ ����.
		int select;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 10);
		switch (level) {
		case 1: {
			cout << "��ȭ ����Ȯ���� 80, ���� Ȯ���� 10, ���� Ȯ���� 10�Դϴ�. ����Ͻðڽ��ϱ�? ����Ϸ��� 1��!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 2) { Upgrade_success(); cout << "��ȭ ����!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "��ȭ ����!!"; }
				else { Destroy(); cout << "���� �������ϴ�! �ʱ�ȭ!"; }
				break;
			}
			else break;
		}
		case 2: {
			cout << "��ȭ ����Ȯ���� 70, ���� Ȯ���� 20, ���� Ȯ���� 10�Դϴ�. ����Ͻðڽ��ϱ�? ����Ϸ��� 1��!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 3) { Upgrade_success(); cout << "��ȭ ����!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "��ȭ ����!!"; }
				else { Destroy(); cout << "���� �������ϴ�! �ʱ�ȭ!"; }
				break;
			}
			else break;
		}
		case 3: {
			cout << "��ȭ ����Ȯ���� 60, ���� Ȯ���� 30, ���� Ȯ���� 10�Դϴ�. ����Ͻðڽ��ϱ�? ����Ϸ��� 1��!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 4) { Upgrade_success(); cout << "��ȭ ����!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "��ȭ ����!!"; }
				else { Destroy(); cout << "���� �������ϴ�! �ʱ�ȭ!"; }
				break;
			}
			else break;
		}
		case 4: {
			cout << "��ȭ ����Ȯ���� 50, ���� Ȯ���� 40, ���� Ȯ���� 10�Դϴ�. ����Ͻðڽ��ϱ�? ����Ϸ��� 1��!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 5) { Upgrade_success(); cout << "��ȭ ����!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "��ȭ ����!!"; }
				else { Destroy(); cout << "���� �������ϴ�! �ʱ�ȭ!"; }
				break;
			}
			else break;
		}
		case 5: {
			cout << "��ȭ ����Ȯ���� 40, ���� Ȯ���� 50, ���� Ȯ���� 10�Դϴ�. ����Ͻðڽ��ϱ�? ����Ϸ��� 1��!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 6) { Upgrade_success(); cout << "��ȭ ����!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "��ȭ ����!!"; }
				else { Destroy(); cout << "���� �������ϴ�! �ʱ�ȭ!"; }
				break;
			}
			else break;
		}
		default: cout << "�̹� �ְ� ������ �����߽��ϴ�." << endl;
		}
	}
	friend istream& operator >> (istream& ins, Weapon& a);
};

istream& operator >> (istream& ins, Weapon& a) {
	cout << "���� ������ ���� ��ȭ Ȯ���� �޶����ϴ�. ��ȭ�� �����Ͻ÷��� 1�� �ƴϸ� 2���� �������ּ���.";
	ins >> a.challenge;
	if (a.challenge == 1) {
		a.Upgrade(a.getLevel());
	}
	else cout << "��ȭ�� �����մϴ�." << endl;
	cout << endl;
	return ins;
}


int main() {
	Weapon DJ_Weapon;
	int select;
	while (1) {
		cout << "�ȳ��ϼ���. ��ȭ�����Դϴ�. ��ȭ ���ӿ� �����Ϸ��� 1��, ���Ḧ ���Ͻø� 2���� �����ּ���. ";
		cin >> select;
		if (select == 1) {
			cin >> DJ_Weapon;
		}
		else if (select == 2) {
			return 0;
		}
		else {
			cout << "�߸� �Էµ� ���Դϴ�. " << endl;
		}

	}
	return 0;
}