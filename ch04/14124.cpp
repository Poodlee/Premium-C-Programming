#include <iostream>
#include <string>
using namespace std;


class Player {
	std::string name;
	void setName(string name) { this->name = name; }
};

class Team {
	Player *Play;
	string name;
	void setTeamName(string name) { this->name = name; }
};

class League {
	Team* Teamss;
	string name;
	void setLeagueName(string name) { this->name = name; }
};

int main() {
	League K_League;
	K_League.setLeagueName(string("°­¿øFC"));
}
