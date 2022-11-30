#include <iostream>
using namespace std;

int main() {
	  
	double number=0,max = 0;
	cout << "5 개의 실수를 입력하라 >>";

	for (int i = 0; i < 5; i++) {
		cin >> number;
		if (i == 0) max = number;
		else
			if (max < number) max = number;
	}
	cout << "가장 큰 수는 = " << max << endl;

}