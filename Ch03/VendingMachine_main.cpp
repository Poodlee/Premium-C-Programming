// VendingMachine_main.cpp

#include <iostream>
#include "VendingMachine.h"

int main() {
	VendingMachine DongJunMachine;

	while (true) {	//���� ����
		int selection, insertCoin, product, end;
		std::cout << "������ ���͵帱���? " << std::endl;
		std::cout << "1. �� �ֱ� " << "2. ��ǰ ���� " << "3. �ܵ� �ޱ�" << " 4. �ܾ� Ȯ��" << std::endl;
		std::cin >> selection;
		switch (selection) {
			case 1: std::cout << "�󸶸� �Ա��Ͻðڽ��ϱ�? " << std::endl;
					std::cin >> insertCoin;
					DongJunMachine.inputMoney(insertCoin); break;
			case 2:
					std::cout << "� ��ǰ�� ���� �Ͻðڽ��ϱ�?? 0. ���� Ȯ�� 1. ���(1000��) 2. ��������Ʈ(1000��)" << std::endl;
					std::cin >> product;
					switch (product) {
					case 0: DongJunMachine.checkproduct(); break;
					case 1: std::cout << "������ �������ּ���.\n" << std::endl;
							int num_pepsi;
							std::cin >> num_pepsi;
							DongJunMachine.buyPepsi(num_pepsi); break;
					case 2: std::cout << "������ �������ּ���.\n" << std::endl;
							int num_sprite;
							std::cin >> num_sprite;
							DongJunMachine.buySprite(num_sprite); break;
					} break;
			case 3: DongJunMachine.returnBalance(); break;
			case 4: DongJunMachine.remainMoney(); break;
			}
		end = DongJunMachine.kill();
		if (end == 0) break;
		std::cout << "\n\n" << std::endl;
	}
};