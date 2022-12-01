#include <iostream>
#include <string>
using namespace std;

int main() {

	string ans;
	char name[100];
	char te[100];
	int max = 0;
	cout << "5명의 이름을 ';'로 구분하여 입력하세요\n" << ">>";

	for (int i = 1; i <= 5; i++) {
		cin.getline(name, 100, ';');
		cout << i << ":" << name<< "\n";
		
		if (max < strlen(name))
		{
			max = strlen(name);
			ans = name;
		}
	}
	cout << "가장 긴 이름은 " << ans << endl;
}