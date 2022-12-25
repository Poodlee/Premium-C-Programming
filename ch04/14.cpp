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
	~GamblingGame() { cout << " ������ �����մϴ�." << endl; }
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
	cout << "*****   �׺� ������ �����մϴ�.   *****" << endl;
	string name;
	cout << "ù��° ���� �̸� >>";
	cin >> name;
	p[0].setName(name);
	cout << "�ι�° ���� �̸� >>";
	cin >> name;
	p[1].setName(name);

	int end = 0;
	while (true) {
		for (int i = 0; i < 2; i++) {
			if (player_turn(p[i].getName())) {
				cout << p[i].getName() << "\t �� �¸�!!";
				end = 1;
				break;
			}
			else
				cout << "�ƽ�����!" << endl;
		}
		if (end == 1) break;
	}
}

int main() {
	GamblingGame DJGame;
	DJGame.game_start();
}