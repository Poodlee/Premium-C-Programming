#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class AbstractPlayer {
	string name;
protected:
	string gbb[3]; //가위,바위,보로 생성자에서 설정
public:
	AbstractPlayer(string name) {
		this->name = name;
		gbb[0] = "가위"; gbb[1] = "바위"; gbb[2] = "보";
	}
	virtual string turn() = 0; //리턴하는 값 가위 바위 보 중 하나
	string getName() { return name; }
};
class Human : public AbstractPlayer {
public:
	Human(string name) : AbstractPlayer(name) { ; }
	string turn() {
		string inn;
		while (1) {
			cout << getName() << ">>";
			getline(cin, inn);
			if (inn == "가위" || inn == "바위" || inn == "보")
				return inn;
		}
	}
};

class Computer : public AbstractPlayer {
public:
	Computer() : AbstractPlayer("Computer") {
		srand((unsigned)time(NULL));
	}
	string turn() {
		int num = rand() % 3;
		return gbb[num];
	}
};

class Game { // run : 출력, 입력, turn 진행, 비교
public:
	void run() {
		string name;
		cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****" << endl;
		cout << "선수 이름을 입력하세요>>";
		getline(cin, name);

		Human h(name);
		Computer c;
		
		while (1) {
			string h_result = h.turn();
			string c_result = c.turn();
			cout << c.getName() << ": " << c_result << endl;
			if (h_result == c_result)
				cout << "the same" << endl;
			else if (h_result == "바위") {
				if (c_result == "가위")
					cout << h.getName() << " is winner." << endl;
				else
					cout << c.getName() << " is winner." << endl;
			}
			else if (h_result == "가위") {
				if (c_result == "보")
					cout << h.getName() << " is winner." << endl;
				else
					cout << c.getName() << " is winner." << endl;
			}
			else if (h_result == "보") {
				if (c_result == "바위")
					cout << h.getName() << " is winner." << endl;
				else
					cout << c.getName() << " is winner." << endl;
			}
		}
	}

};
int main() {
	Game DJ_Game;
	DJ_Game.run();
}