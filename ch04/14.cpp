#include <iostream>
#include <string>
#include <random>
using namespace std;

class Player {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};



class GamblingGame {
	Player p[2];
public:
	bool player_turn(string name);
	void game_start();
	~GamblingGame() { cout << " 게임을 종료합니다." << endl; }
};

bool GamblingGame::player_turn(string name) {
	
	cout << name << ": <Enter>";
	string enter;
	getline(cin, enter, '\n');
	cout << endl << endl;
	
	int result[3];
	for (int i = 0; i < 3; i++) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, 2);
		result[i] = dis(gen);

		cout << "\t" << result[i];
	}
	if (result[0] == result[1] && result[1] == result[2])
		return true;
	else
		return false;
}

void GamblingGame::game_start() {
	cout << "*****   겜블링 게임을 시작합니다.   *****" << endl;
	string name;
	cout << "첫번째 선수 이름 >>";
	cin >> name;
	p[0].setName(name);
	cout << "두번째 선수 이름 >>";
	cin >> name;
	p[1].setName(name);

	int end = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (player_turn(p[i].getName())) {
				cout << p[i].getName() << "\t 님 승리!!";
				end = 1;
				break;
			}
			else
				cout << "아쉽군요!" << endl;
		}
		if (end == 1) break;
	}
}

int main() {
	GamblingGame DJGame;
	DJGame.game_start();
}