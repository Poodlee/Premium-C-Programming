#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class AbstractPlayer {
	string name;
protected:
	string gbb[3]; //����,����,���� �����ڿ��� ����
public:
	AbstractPlayer(string name) {
		this->name = name;
		gbb[0] = "����"; gbb[1] = "����"; gbb[2] = "��";
	}
	virtual string turn() = 0; //�����ϴ� �� ���� ���� �� �� �ϳ�
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
			if (inn == "����" || inn == "����" || inn == "��")
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

class Game { // run : ���, �Է�, turn ����, ��
public:
	void run() {
		string name;
		cout << "***** ��ǻ�Ϳ� ����� ���� ���� �� ����� ��Ĩ�ϴ�. *****" << endl;
		cout << "���� �̸��� �Է��ϼ���>>";
		getline(cin, name);

		Human h(name);
		Computer c;
		
		while (1) {
			string h_result = h.turn();
			string c_result = c.turn();
			cout << c.getName() << ": " << c_result << endl;
			if (h_result == c_result)
				cout << "the same" << endl;
			else if (h_result == "����") {
				if (c_result == "����")
					cout << h.getName() << " is winner." << endl;
				else
					cout << c.getName() << " is winner." << endl;
			}
			else if (h_result == "����") {
				if (c_result == "��")
					cout << h.getName() << " is winner." << endl;
				else
					cout << c.getName() << " is winner." << endl;
			}
			else if (h_result == "��") {
				if (c_result == "����")
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