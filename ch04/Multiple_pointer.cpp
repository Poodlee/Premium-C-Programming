#include <iostream>
#include <string>
using namespace std;

class Player {       //각각의 선수 이름, 키 그리고 몸무게 등록. 
private:
	string name;
	int height, weight;
public:
	void set(string name, int height, int weight)
	{
		this->name = name, this->height = height, this->weight = weight;
	}
	string getName() { return name; }
	int getSpec() { return height, weight; }
};

class team {
private:
	Player* p;
	string TeamName;
	int size;
public:
	team() { p = new Player[5]; }
	team(string name, int size) {
		p = new Player[size]; this->size = size; this->TeamName = name;
	}
	void setPlayer(int num, string named, int height, int weight) {
		p[num].set(named, height, weight);
	}
	string getName(int num) { return p[num].getName(); }
	int getSpec(int num) { return p[num].getSpec(); }
};

class League {
private:
	team* t;
	string LeagueName;
	int size;
public:
	League(string name, int size) {
		t = new team[size]; this->size = size; this->LeagueName = name;
	}
	void setPlayer(int num_team, int num_player, string nameed, int height, int weight ) {
		t[num_team].setPlayer(num_player, nameed, height, weight);
	}
	string getName(int num_team, int num_Player) {
		return t[num_team].getName(num_Player);
	}
	int getSpec(int num_team, int num_Player) {
		return 	t[num_team].getSpec(num_Player);
	}
};

int main() {
	string s,s2;
	int s3, s4;
	League K_League("K_League", 4);
	K_League.setPlayer(1, 1, "Alpha", 170, 70);
	K_League.setPlayer(1, 2, "Delta", 160, 60);
	s = K_League.getName(1, 1);
	s2 = K_League.getName(1, 2);
	s3 = K_League.getSpec(1, 1);
	s4 = K_League.getSpec(1, 2);
	std::cout << s << " " << s2 << " " << s3 << " " << s4;

}