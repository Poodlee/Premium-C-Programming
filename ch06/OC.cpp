#include <iostream>
#include <string>
#include <random>
using namespace std;

class Person {
	string name[2];
	int n=-1;
public:
	Person() { name[0] = "김인수"; name[1] = "오은경"; }
	string getName() {
		// 0부터 시작해서 0~1 0~1 해야 한다.
		n++;
		if (n >= 2) {
			n = 0;
			return name[n];
		}
		else return name[n];
	}
};

class UpAndDownGame {
private:
	static int min, max, result;
public:
	static void game();
};
int UpAndDownGame::min = 0;
int UpAndDownGame::max = 99;
int UpAndDownGame::result = 0;
void UpAndDownGame::game() {
	int number;
	Person p;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(min, max);
	result = dis(gen);
	
	cout << "Up & Down 게임을 시작합니다." << endl;
	while (true) {
		string name = p.getName();
		cout << "답은 " << min <<"과 "<< max << "사이에 있습니다." << endl;
		cout << name << ">>";
		cin >> number;
		
		if (number > result)
			max = number;
		else if (number < result)
			min = number;
		else {
			cout << name << "이(가) 이겼습니다!!" << endl;
			break;
		}
	}
}

int main(){
	UpAndDownGame dj_game;
	dj_game.game();
}