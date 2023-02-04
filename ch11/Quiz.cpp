#include <iostream>
#include <random>
using namespace std;

// 강화 게임
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
	void Upgrade(int level) { // 레벨이 높아질 수록 성공확률 (80->70->60...) 실패 확률(10->20->30...) 터질 확률(10) 최대 5강까지 가능.
		int select;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 10);
		switch (level) {
		case 1: {
			cout << "강화 성공확률이 80, 실패 확률이 10, 터질 확률이 10입니다. 계속하시겠습니까? 계속하려면 1번!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 2) { Upgrade_success(); cout << "강화 성공!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "강화 실패!!"; }
				else { Destroy(); cout << "빵빵 터졌습니다! 초기화!"; }
				break;
			}
			else break;
		}
		case 2: {
			cout << "강화 성공확률이 70, 실패 확률이 20, 터질 확률이 10입니다. 계속하시겠습니까? 계속하려면 1번!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 3) { Upgrade_success(); cout << "강화 성공!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "강화 실패!!"; }
				else { Destroy(); cout << "빵빵 터졌습니다! 초기화!"; }
				break;
			}
			else break;
		}
		case 3: {
			cout << "강화 성공확률이 60, 실패 확률이 30, 터질 확률이 10입니다. 계속하시겠습니까? 계속하려면 1번!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 4) { Upgrade_success(); cout << "강화 성공!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "강화 실패!!"; }
				else { Destroy(); cout << "빵빵 터졌습니다! 초기화!"; }
				break;
			}
			else break;
		}
		case 4: {
			cout << "강화 성공확률이 50, 실패 확률이 40, 터질 확률이 10입니다. 계속하시겠습니까? 계속하려면 1번!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 5) { Upgrade_success(); cout << "강화 성공!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "강화 실패!!"; }
				else { Destroy(); cout << "빵빵 터졌습니다! 초기화!"; }
				break;
			}
			else break;
		}
		case 5: {
			cout << "강화 성공확률이 40, 실패 확률이 50, 터질 확률이 10입니다. 계속하시겠습니까? 계속하려면 1번!" << endl;
			cin >> select;
			if (select == 1) {
				if (dis(gen) >= 6) { Upgrade_success(); cout << "강화 성공!!"; }
				else if (dis(gen) >= 1) { Upgrade_fail(); cout << "강화 실패!!"; }
				else { Destroy(); cout << "빵빵 터졌습니다! 초기화!"; }
				break;
			}
			else break;
		}
		default: cout << "이미 최고 레벨에 도달했습니다." << endl;
		}
	}
	friend istream& operator >> (istream& ins, Weapon& a);
};

istream& operator >> (istream& ins, Weapon& a) {
	cout << "현재 래벨에 따라 강화 확률은 달라집니다. 강화에 도전하시려면 1번 아니면 2번을 선택해주세요.";
	ins >> a.challenge;
	if (a.challenge == 1) {
		a.Upgrade(a.getLevel());
	}
	else cout << "강화를 종료합니다." << endl;
	cout << endl;
	return ins;
}


int main() {
	Weapon DJ_Weapon;
	int select;
	while (1) {
		cout << "안녕하세요. 강화게임입니다. 강화 게임에 참석하려면 1번, 종료를 원하시면 2번을 눌러주세요. ";
		cin >> select;
		if (select == 1) {
			cin >> DJ_Weapon;
		}
		else if (select == 2) {
			return 0;
		}
		else {
			cout << "잘못 입력된 값입니다. " << endl;
		}

	}
	return 0;
}