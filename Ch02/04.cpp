#include <iostream>
using namespace std;

int main() {
	  
	double number=0,max = 0;
	cout << "5 ���� �Ǽ��� �Է��϶� >>";

	for (int i = 0; i < 5; i++) {
		cin >> number;
		if (i == 0) max = number;
		else
			if (max < number) max = number;
	}
	cout << "���� ū ���� = " << max << endl;

}