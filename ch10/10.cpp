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

class Game { //main 깔끔하게 하기 위해서
private:
	vector<Nation> v;
	void insert()
	{
		cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
		cout << "나라와 수도를 입력하세요(no no 이면 입력끝)" << endl;
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
		cout << "퀴즈를 시작하겠습니다. 종료를 원하시면 exit를 입력해주세요." << endl;
		srand((unsigned)time(0));
		int n;
		string bogi, answer;
		string input;
		while (1)
		{
			n = rand() % v.size();
			bogi = v.at(n).getNation();
			answer = v.at(n).getCapital();
			cout << bogi << "의 수도는?";
			cin >> input;

			if (input == "exit") break;
			if (input == answer) { cout << "Correct !!" << endl; }
			else { cout << "NO !! " << endl; }

		}
	}
public:
	Game() {
		v.push_back(Nation("한국", "서울"));
		v.push_back(Nation("일본", "도쿄"));
		v.push_back(Nation("중국", "베이징"));
		v.push_back(Nation("미국", "워싱턴"));
		v.push_back(Nation("러시아", "모스크바"));
		v.push_back(Nation("이탈리아", "로마"));
		v.push_back(Nation("프랑스", "파리"));
		v.push_back(Nation("영국", "런던"));
		v.push_back(Nation("우크라이나", "키이우"));
	}
	void run()
	{
		cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****<<" << endl;
		int choice;
		while (1)
		{
			cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >>";
			cin >> choice;
			switch (choice) {
			case 1: insert(); break;
			case 2: quiz(); break;
			case 3: return;
			default: cout << "잘못된 입력입니다." << endl;
			}

		}

	}

};

int main() {
	Game DJgame;
	DJgame.run();
}