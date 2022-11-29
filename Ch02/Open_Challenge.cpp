#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "로미오>>";
	cin >> s; 
	
	string t;
	cout << "줄리엣>>";
	cin >> t;

	if (s == "가위" && t == "보")
		cout << "로미오가 이겼습니다." << endl;
	
}