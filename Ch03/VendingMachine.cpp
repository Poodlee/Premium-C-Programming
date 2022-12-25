//VendingMachine.cpp

#include <iostream>
#include "VendingMachine.h"

void VendingMachine::inputMoney(int money) {
	balance += money;
	std::cout << money << "���� �ԱݵǾ� ���� �ܾ��� " << balance << " �Դϴ�. \n";

}
void VendingMachine::remainMoney() {
	std::cout << "�ܾ��� " << balance << "�Դϴ�. \n";
}
void VendingMachine::buyPepsi(int cnt) { 
	if (balance >= 1000 * cnt) {
		if (pepsi == 0)
			std::cout << "�층 !! ǰ���Դϴ�. \n";
		else if (pepsi > 0 && pepsi < cnt)
			std::cout << "�����Ϸ��� �������� ����� ������ �� �����ϴ�. \n" << std::endl;
		else
			balance -= 1000*cnt;
			pepsi -= cnt;
			std::cout << "��ī�ݶ� " << cnt << "�� ���ְ� �弼��!\n";
	}
	else { std::cout << "�층!�ܾ� �����Դϴ�! \n"; }
}
void VendingMachine::buySprite(int cnt) {
	if (balance >= 1000 * cnt) {
		if (sprite == 0) {
			std::cout << "�층 !! ǰ���Դϴ�. \n";
		}
		else if (sprite > 0 && sprite < cnt) {
			std::cout << "�����Ϸ��� �������� ����� ������ �� �����ϴ�. \n" << std::endl;
		}
		else {
			balance -= 1000 * cnt;
			sprite -= cnt;
			std::cout << "���̴� " << cnt << "�� ���ְ� �弼��!\n";
		}
	}
	else { std::cout << "�층! �ܾ� �����Դϴ�! \n"; }
}
void VendingMachine::returnBalance() {
	if (balance > 0) {
		std::cout << balance << "�� �ܾ����� ���� ���� �帳�ϴ�.\n �ȳ��� ������!!\n";
		balance = 0;
	}
	else {
		std::cout << "���� �ܾ��� ���׿� �Ф�";

	}
}
void VendingMachine::checkproduct() {
	std::cout << "���� ���� �ִ� ��ô� " << pepsi << "�� �̰� ���� �ִ� ��������Ʈ�� " << sprite << "�� �Դϴ�." << std::endl;
}
bool VendingMachine::kill() {
	if (pepsi == 0 && sprite == 0) {
		int select;
		std::cout << "���Ǳ��� ��� ��ǰ�� ǰ�� �ƽ��ϴ�.\n ���԰� �Ͻðڽ��ϱ�?? ���԰�:1 ����:2\n";
		std::cin >> select;
		switch (select) {
		case 1: {std::cout << "��� �԰��߽��ϴ�. �ٽ� ��ÿ� ���̴� ���� 10�� �Դϴ�.\n";
			pepsi = 10; sprite = 10; return 1; }
		case 2: std::cout << "��� �����մϴ�."; return 0;
		}
	}
	else {
		return 1;
	}
}