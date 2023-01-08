#include <iostream>
#include <string>
#include <random>
using namespace std;

class Person {
	string name[2];
	int n=-1;
public:
	Person() { name[0] = "���μ�"; name[1] = "������"; }
	string getName() {
		// 0���� �����ؼ� 0~1 0~1 �ؾ� �Ѵ�.
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
	
	cout << "Up & Down ������ �����մϴ�." << endl;
	while (true) {
		string name = p.getName();
		cout << "���� " << min <<"�� "<< max << "���̿� �ֽ��ϴ�." << endl;
		cout << name << ">>";
		cin >> number;
		
		if (number > result)
			max = number;
		else if (number < result)
			min = number;
		else {
			cout << name << "��(��) �̰���ϴ�!!" << endl;
			break;
		}
	}
}

int main(){
	UpAndDownGame dj_game;
	dj_game.game();
}