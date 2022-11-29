#include <iostream>
#include <string>
using namespace std;

int main() {
	string p("I always hard hard");
	string s;
	cout << "로미오>>";
	cin >> s; 
	
	string t;
	cout << "줄리엣>>";
	cin >> t;

	string z;
	cin >> z;

	if (s == "가위" && t == "보" && z == p)
		cout << "로미오가 이겼습니다." << endl;
	
	
}