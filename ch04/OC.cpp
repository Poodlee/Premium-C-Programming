#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:
	void set_name(string name) { this->name = name; }
	string get_name() { return name; }
};

class WordGame {
	Player* p;
	int count;
	string before, after;
public:
	WordGame();
	~WordGame() { delete[]p; }
	void gamestart();
};

WordGame::WordGame() {
	string name;
	cout << "���� �ձ� ������ �����մϴ�.\n";
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	cin >> count;
	p = new Player[count];
	for (int i = 0; i < count; i++) {
		cout << "�������� �̸��� �Է��ϼ���. ��ĭ ���� >>";
		cin >> name;
		p[i].set_name(name);
	}
}
void WordGame::gamestart() {
	int i = 0;
	cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�." << endl;
	before = "�ƹ���";
	while (true) {
		cout << p[i].get_name() << ">>";
		cin >> after;
		int size = before.size();
		if (before.at(size - 2) == after.at(0) && before.at(size - 1) == after.at(1)) {
			before = after;
			i++;
		}
		else {
			cout << p[i].get_name() << "�� �����ϴ�.";
			break;
		}
		if (i == count) {
			i = 0;
		}
	}

}


int main() {
	WordGame game;
	game.gamestart();


}