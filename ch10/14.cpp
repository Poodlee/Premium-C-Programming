#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	map<string, string> manager;
	string name, password;
	int choice;

	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****" << endl;
	while (1) {
		cout << "����:1, �˻�:2, ����:3 >>";
		cin >> choice;
		switch (choice) {
		case 1: {
			cout << "�̸��� ��ȣ>> ";
			cin >> name >> password;
			manager[name] = password; //���
			break;
		}
		case 2: {
			cout << "�̸�>> ";
			cin >> name;
			while (1) {
				if (manager.find(name) == manager.end()) cout << "ã�� �� �����ϴ�." << endl;
				else {
					cout << "��ȣ? ";
					cin >> password;
					if (password == manager[name]) { cout << "���!!" << endl; break; }
					else { cout << "����~~" << endl; }
				}
			}
			break;
		}
		case 3: {
			cout << "���α׷��� �����մϴ�..." << endl;
			return 0;
		}
		}
	}
}