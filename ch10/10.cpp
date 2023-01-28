#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Nation {
private:
	string nation;
	string capital;
public:
	Nation(string nation = "", string capital = "") {
		this->nation = nation; this->capital = capital;
	}
	string getNation() { return nation; }
	string getCapital() { return capital; }
};

class Game { //main ����ϰ� �ϱ� ���ؼ�
private:
	vector<Nation> v;
	void insert()
	{
		cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�." << endl;
		cout << "����� ������ �Է��ϼ���(no no �̸� �Է³�)" << endl;
		while (1)
		{
			string nation, capital;
			cout << v.size() + 1 << ">>";
			cin >> nation >> capital;
			if (nation == "no" && capital == "no") break;
			if (check(nation)) cout << "already exists !! " << endl;
			else v.push_back(Nation(nation, capital));
		}
	}
	bool check(string nation)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].getNation() == nation) return true;
		}
		return false;
	}
	void quiz() {
		cout << "��� �����ϰڽ��ϴ�. ���Ḧ ���Ͻø� exit�� �Է����ּ���." << endl;
		srand((unsigned)time(0));
		int n;
		string bogi, answer;
		string input;
		while (1)
		{
			n = rand() % v.size();
			bogi = v.at(n).getNation();
			answer = v.at(n).getCapital();
			cout << bogi << "�� ������?";
			cin >> input;

			if (input == "exit") break;
			if (input == answer) { cout << "Correct !!" << endl; }
			else { cout << "NO !! " << endl; }

		}
	}
public:
	Game() {
		v.push_back(Nation("�ѱ�", "����"));
		v.push_back(Nation("�Ϻ�", "����"));
		v.push_back(Nation("�߱�", "����¡"));
		v.push_back(Nation("�̱�", "������"));
		v.push_back(Nation("���þ�", "��ũ��"));
		v.push_back(Nation("��Ż����", "�θ�"));
		v.push_back(Nation("������", "�ĸ�"));
		v.push_back(Nation("����", "����"));
		v.push_back(Nation("��ũ���̳�", "Ű�̿�"));
	}
	void run()
	{
		cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****<<" << endl;
		int choice;
		while (1)
		{
			cout << "���� �Է�: 1, ����: 2, ����: 3 >>";
			cin >> choice;
			switch (choice) {
			case 1: insert(); break;
			case 2: quiz(); break;
			case 3: return;
			default: cout << "�߸��� �Է��Դϴ�." << endl;
			}

		}

	}

};

int main() {
	Game DJgame;
	DJgame.run();
}