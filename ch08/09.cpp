#include <iostream>
#include <string>
using namespace std;

// ����� ���� ���α׷�
// �װ��� �̸�: �Ѽ��װ�, 8���� �¼�.3���� �����. ���� �λ� �� ����
// �� ����� �Ϸ翡 �� ���� ����. �ð� 07��,12��,17��.
// ������ ���: ����, ���, ���� ����
// ����: ���� �ð�, ����� �̸�, �¼� ��ȣ �Է� �޾� ����
// ���: ���� �ð�, ����� �̸�, �¼� ��ȣ �Է¹ް� ���� ��� 
// ������ �迭�� ������ �ȴ�. ��Ҵ� �����ؾ� �ϴµ� ��.. 316p 6�� �����ϸ� �� ���ϴ�. ���� ������ ����
// �ƴϸ� �׳� �ٽ� add�� �迭�� ���п� ���� �ֱ�? 
// ���൵ ���� �ð� �˷��ְ� �����ϱ�.

// �װ��� �� 3���� ����� ����
// �� ������ ������ seat�� timetable�� �� �ڸ� ����
// �� ����⿡�� ����, ���� ���, ����Ȯ���� ���� �Ѵ�. 
class airline {
	string airline_name;
public:
	airline() {;}
	airline(string name) {
		this->airline_name = name;
	}
};
//������ �� ����� �����ϸ� ���� �ð��� ���� �ڸ� ����Ʈ ���.
class airplane : public airline {
public:
	int seat[8];			// �ڸ��� ���� ������ 0. �����̸� 1.
	string name[8];			// ������ �̸� Ȯ�ο�
	airplane() { 
		for (int i = 0; i < 8; i++) { seat[i] = 1; name[i] = "0"; }
	}
	void checkVacancy();
	bool checkVacancy2();
	void reserve(int time,string names, int seatNumber);
	void check_reserve(int time,string names, int seatNumber);
	void cancel_reserve(int time,string names, int seatNumber);
};

void airplane::checkVacancy() {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (seat[i] == 1) cnt++;
		}
	cout << "���� �ش� �ð� ����⿡ ���� �¼��� " << cnt << "����  ";
		for (int i = 0; i < 8; i++) { 
			if (seat[i] == 1) cout << i+1 << ' ';
		}
		cout << "�� ���� �ֽ��ϴ�." << endl;
	if (cnt == 0) {
		cout << "�ش� �ð� ����⿡ ���� �¼��� �����ϴ�.";
	}
}

bool airplane::checkVacancy2() {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int i = 0; i < 8; i++) {
			if (seat[i] == 1) cnt++;
		}
		}
	if (cnt == 0) { return false; }
	else return true;
}


void airplane::reserve(int time,string names, int seatNumber) {
	if (seat[seatNumber-1] == 0 || name[seatNumber-1] != "0") {
		cout << "�ش� �¼��� �̹� �ٸ� ����� �����߿� �ֽ��ϴ�." << endl;
	}
	else { seat[seatNumber-1] = 0; name[seatNumber-1] = "names";
		cout << names << "�� " << time << "�ÿ� ����ϴ� ������� " << seatNumber << "�� �¼��� ���� �Ϸ� �ƽ��ϴ�." << endl;
	}
}

void airplane::check_reserve(int time,string names, int seatNumber) {
	cout << endl << "-------------------------��ȸ ���Դϴ�.-----------------" << endl << endl;
	if (seat[seatNumber-1] == 0 && name[seatNumber-1] == "names") {
		cout << names << "���� ���� " << time << "�ÿ� ����ϴ� ������� " << seatNumber << "�� �¼��� ������ �Ǿ� �ֽ��ϴ�." << endl;
	}
	else {
		cout << "�ش� ������ �����ϴ� ���� ����� �����ϴ�." << endl;
	}
}

void airplane::cancel_reserve(int time,string names, int seatNumber) {
	if (seat[seatNumber-1] == 0 && name[seatNumber-1] == "names") {
		cout << names << "���� ���� " << time << "�ÿ� ����ϴ� ������� " << seatNumber << "�� �¼��� ���� ������ ����Ͻðڽ��ϱ�?(y/n)";
		char yes_no;
		cin >> yes_no;
		if (yes_no == 'n') return;
		else {
			seat[seatNumber-1] = 1; name[seatNumber-1] = '0';
			cout << names << "���� ���� ��Ҹ� �Ϸ��߽��ϴ�." << endl;
		}
	}
	else {
		cout << "�ش� ������ �����ϴ� ���� ����� �����ϴ�." << endl;
	}
}

void response(airplane& air1, airplane& air2, airplane& air3) {
	cout << endl << "�ȳ��Ͻʴϱ� ���� �Ѽ��װ��Դϴ�." << endl;
	cout << "���� ����� 07��, 12��, 17�� �װ����� �����մϴ�. �� �� ������ ���õ� ������ ����ϽǱ��?";
	int times,seatNumber;
	int function;
	string name;
	cin >> times;
	cout << endl;
	if (times == 7) {
		cout << "������ ���� 07�� �����1�� ���õǼ� ��� ������ �ʿ��ϽŰ���?" << endl;
		cout << "1. ����, 2.���� ���, 3.���� Ȯ��"; 
		cin >> function;
		switch (function) {
			case 1: {
				air1.checkVacancy();
				if (air1.checkVacancy2() == 1) {
					cout << "������ �����ϱ� ���ؼ� ������ ����Ͻø� �̸�, �¼���ȣ ������� �Է����ּ���.";
					cin >> name >> seatNumber;
					air1.reserve(7,name, seatNumber); break;
				}
				else break;
			}
			case 2: {
				cout << "���� ��Ҹ� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
				cin >> name >> seatNumber;
				air1.cancel_reserve(7,name, seatNumber); break;
			}
			case 3: {
				cout << "���� Ȯ���� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
				cin >> name >> seatNumber;
				air1.check_reserve(7,name, seatNumber); break;
			}
		}
	}
	if (times == 12) {
		cout << "������ ���� 12�� �����1�� ���õǼ� ��� ������ �ʿ��ϽŰ���?" << endl;
		cout << "1. ����, 2.���� ���, 3.���� Ȯ��";
		cin >> function;
		switch (function) {
		case 1: {
			air2.checkVacancy();
			if (air2.checkVacancy2() == 1) {
				cout << "������ �����ϱ� ���ؼ� ������ ����Ͻø� �̸�, �¼���ȣ ������� �Է����ּ���.";
				cin >> name >> seatNumber;
				air2.reserve(12, name, seatNumber); break;
			}
			else break;
		}
		case 2: {
			cout << "���� ��Ҹ� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
			cin >> name >> seatNumber;
			air2.cancel_reserve(12, name, seatNumber); break;
		}
		case 3: {
			cout << "���� Ȯ���� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
			cin >> name >> seatNumber;
			air2.check_reserve(12, name, seatNumber); break;
		}
		}
	}
	if (times == 17) {
		cout << "������ ���� 17�� �����1�� ���õǼ� ��� ������ �ʿ��ϽŰ���?" << endl;
		cout << "1. ����, 2.���� ���, 3.���� Ȯ��";
		cin >> function;
		switch (function) {
		case 1: {
			air3.checkVacancy();
			if (air3.checkVacancy2() == 1) {
				cout << "������ �����ϱ� ���ؼ� ������ ����Ͻø� �̸�, �¼���ȣ ������� �Է����ּ���.";
				cin >> name >> seatNumber;
				air3.reserve(17, name, seatNumber); break;
			}
			else break;
		}
		case 2: {
			cout << "���� ��Ҹ� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
			cin >> name >> seatNumber;
			air3.cancel_reserve(17, name, seatNumber); break;
		}
		case 3: {
			cout << "���� Ȯ���� �����ϱ� ���ؼ� �̸�, �¼���ȣ ������� �Է����ּ���.";
			cin >> name >> seatNumber;
			air3.check_reserve(17, name, seatNumber); break;
		}
		}
	}
}

int main() {
	airline airline_Hansung("�Ѽ��װ�");
	airplane airplane1, airplane2, airplane3;
	while (true) {
		response(airplane1, airplane2, airplane3);
	}
}