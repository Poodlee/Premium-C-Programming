#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> manager;
	string name;
	int choice,score;
	
	cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << endl;
	while (1) {
		cout << "�Է�:1, ��ȸ:2, ����:3 >>";
		cin >> choice;
		switch(choice) {
		case 1: {
			cout << "�̸��� ����>> ";
			cin >> name >> score;
			manager[name] = score; //���
			break;
		}
		case 2: {
			cout << "�̸�>> ";
			cin >> name;
			if (manager.find(name) == manager.end()) cout << "ã�� �� �����ϴ�." << endl;
			else cout << name << "�� ������ " << manager[name] << endl;
			break;
		}
		case 3: {
			cout << "���α׷��� �����մϴ�..." << endl;
			return 0;
		}
		}
	}
}