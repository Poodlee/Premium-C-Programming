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
	cout << "끝말 잇기 게임을 시작합니다.\n";
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	cin >> count;
	p = new Player[count];
	for (int i = 0; i < count; i++) {
		cout << "참가자의 이름을 입력하세요. 빈칸 없이 >>";
		cin >> name;
		p[i].set_name(name);
	}
}
void WordGame::gamestart() {
	int i = 0;
	cout << "시작하는 단어는 아버지입니다." << endl;
	before = "아버지";
	while (true) {
		cout << p[i].get_name() << ">>";
		cin >> after;
		int size = before.size();
		if (before.at(size - 2) == after.at(0) && before.at(size - 1) == after.at(1)) {
			before = after;
			i++;
		}
		else {
			cout << p[i].get_name() << "이 졌습니다.";
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