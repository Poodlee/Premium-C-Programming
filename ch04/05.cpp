#include <iostream>
#include <string>
#include <random>
using namespace std;

int main() {
	string str;
	
	while (true) {
		cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�.)" << endl;
		cout << " >>";
		getline(cin, str, '\n');
		if (str == "exit") {
			break;
		}
		int result;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<int> dis(0, str.size());
		result = dis(gen);
		
		char alpha = result % 26 + 'a';

		str[result] = alpha;
		cout << str << endl;
	}
	
	

}