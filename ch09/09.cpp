#include <iostream>
#include <string>
using namespace std;

class printer {
	string model, manufacture;
	int printedCount, availableCount;
public:
	printer(string model, string manufacture, int availableCount) {
		this->model = model; this->manufacture = manufacture; this->availableCount = availableCount;
	}
	void print(int pages) { this->availableCount -= pages; }
	string getModel() { return model; }
	string getManufacture() { return manufacture; }
	int getAvailableCount() { return availableCount; }
};

class Inkjet_printer : public printer {
	int availableInk;
public:
	Inkjet_printer(string model, string manufacture, int printedCount, int availableInk) : printer(model, manufacture, printedCount)
	{
		this->availableInk = availableInk;
	}
	void printInkJet(int pages) {
		this->availableInk -= pages;
		print(pages);
	}
	void show() {
		cout << "��ũ�� : " << getModel() << " ," << getManufacture() << " ,���� ���� "
			<< getAvailableCount() << "�� ,���� ��ũ " << availableInk << endl;
	}
	int getInk() { return availableInk; }
};

class Laser_printer : public printer {
	int availableToner;
public:
	Laser_printer(string model, string manufacture, int printedCount, int availableToner) : printer(model, manufacture, printedCount)
	{
		this->availableToner = availableToner;
	}
	void printLaser(int pages) {
		this->availableToner -= pages;
		print(pages);
	}
	void show() {
		cout << "������ : " << getModel() << " ," << getManufacture() << " ,���� ���� "
			<< getAvailableCount() << "�� ,���� ��� " << availableToner << endl;
	}
	int getToner() { return availableToner; }
};

int main() { //�Է��� ���� �ʴ´�. ���� �����Ǿ���.
	Inkjet_printer *inkprinter = new Inkjet_printer("Officejet V40", "HP", 5, 10);
	Laser_printer *laserprinter = new Laser_printer("SCX - 6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	inkprinter->show();
	laserprinter->show();

	int printer, paper;
	char yes_no;
	while (true) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		std::cin >> printer >> paper;
		switch (printer) {
		case 1: {
			if (inkprinter->getAvailableCount() < paper || inkprinter->getInk() < paper) {
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				inkprinter->show();
				laserprinter->show(); break;
			}
			else {
				cout << "�������Ͽ����ϴ�." << endl;
				inkprinter->printInkJet(paper);
				inkprinter->show();
				laserprinter->show(); break;
			}
		}
		case 2: {
			if (laserprinter->getAvailableCount() < paper || laserprinter->getToner() < paper) {
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				inkprinter->show();
				laserprinter->show(); break;
			}
			else {
				cout <<"�������Ͽ����ϴ�."<<endl;
				laserprinter->printLaser(paper);
				inkprinter->show();
				laserprinter->show(); break;
			}
		}
		}
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		std::cin >> yes_no;
		if (yes_no == 'n') break;
		else continue;
	}
}