#include <iostream>
#include <string>
using namespace std;

class person {
	string name;
	string tel;
public:
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) { this->name = name, this->tel = tel; }
};

int main() {
	
	person Personal[3];
	string name, tel;

	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���." << endl;
	for (int i = 0; i < 3; i++) {
		cout << "��� " << i << " >> ";
		cin >> name >> tel;
		Personal[i].set(name, tel);
	}
	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) {
		cout << Personal[i].getName() << ' ';
	}
	cout << endl;

	cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ��� >> ";
	cin >> name;

	int index = -1;
	for (int i = 0; i < 3; i++) {
		if (Personal[i].getName() == name) {
			index = i;
			break;
		}
	}

	if (index == -1) { cout << "�������� �ʴ� �̸��Դϴ�." << endl; }
	else { cout << "��ȭ��ȣ��" << Personal[index].getTel() << endl; }

}

