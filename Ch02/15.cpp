#include <iostream>
#include <string>

using namespace std;

// Reference. https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm 
// strtok -> 어떠한 기준으로 문자열을 나누는 것

int main() {
	int a, c;
	char b;
	while (true)
	{
		int a, c;
		char b;
		while (true)
		{
			cout << "? ";
			cin >> a >> b >> c;
			switch (b) {
			case '+':cout << a << " " << b << " " << c << " = " << a + c << endl; break;
			case '-':cout << a << " " << b << " " << c << " = " << a - c << endl; break;
			case '*':cout << a << " " << b << " " << c << " = " << a * c << endl; break;
			case '/':cout << a << " " << b << " " << c << " = " << a / c << endl; break;
			case '%':cout << a << " " << b << " " << c << " = " << a % c << endl; break;
			default: cout << "잘못된 연산자 입니다." << endl;
			}
		}
	}

}
