#include <iostream>
#include <string>

using namespace std;

// Reference. https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm 
// strtok -> ��� �������� ���ڿ��� ������ ��

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
			default: cout << "�߸��� ������ �Դϴ�." << endl;
			}
		}
	}

}
