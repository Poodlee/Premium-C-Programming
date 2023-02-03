#include <iostream>
#include <map>
using namespace std;

class Program {
	map<string, string> m;
	void print() {
		map<string, string>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			cout << it->first << " : " << it->second << endl;
		}
	}
public:
	Program() {
		m["Header"] = "0x55 0x55";
		m["Length"] = "0x08";
		m["Command"] = "0x03";
		m["Parameter"] = "0x01 0xE8 0x03 0x01 0xD0 0x07";
	}
	void run() { print(); }
};

int main() {
	Program DJ_Program;
	DJ_Program.run();
}