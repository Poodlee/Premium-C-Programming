#include <iostream>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume(int n) { size -= n; }
	int getSize() { return size; }
};

class coffeeVendingMachine {
	Container tong[3];	//tong[0] : Ŀ��, tong[1] : ��, tong[2]: ������
	void fill() {
		for (int i = 0; i < 3; i++) {
			tong[i].fill();
	} 
		cout << " Ŀ�� " << tong[0].getSize() << " �� " << tong[1].getSize() << " ���� " << tong[2].getSize() << endl;
	}
	void selectEspresso() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 1) {
			tong[0].consume(1);
			tong[1].consume(1);
			cout << "���������� �弼��\n";
		}
		else	cout << "���ᰡ �����մϴ�.\n";
	}
	void selectAmericano() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2) {
			tong[0].consume(1);
			tong[1].consume(2);
			cout << "�Ƹ޸�ī�� �弼��\n";
		}
		else	cout << "���ᰡ �����մϴ�.\n";
	}
	void selectSugarCoffee() {
		if (tong[0].getSize() >= 1 && tong[1].getSize() >= 2 && tong[2].getSize() >= 1) {
			tong[0].consume(1);
			tong[1].consume(2);
			tong[2].consume(1);
			cout << "����Ŀ�� �弼��\n";
		}
		else	cout << "���ᰡ �����մϴ�.\n";
	}
	void show() {
		cout << " Ŀ�� " << tong[0].getSize() << " �� " << tong[1].getSize() << " ���� " << tong[2].getSize() << endl;
	}
public:
	void run();
};

void coffeeVendingMachine::run() {
	
	cout << "*****  Ŀ�����Ǳ⸦ �۵��մϴ�.  *****" << endl;
	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���) >> ";
		int select;
		cin >> select;
		switch (select) {
		case 1:  selectEspresso(); break;
		case 2: selectAmericano(); break;
		case 3: selectSugarCoffee(); break;
		case 4: show(); break;
		case 5: fill(); break;
		}
	}
}

int main() {
	coffeeVendingMachine DongJunMachine;
	DongJunMachine.run();

	return 0;
}