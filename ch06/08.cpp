#include <iostream>
#include <string>
using namespace std;
#define MAX_NUMBER 1000

class Trace { 
	//뒤의 9번이랑 비슷하네
private:
	static int index;
	static string tag[MAX_NUMBER];
	static string info[MAX_NUMBER];
public:
	static void put(string t, string in);
	static void print(string t = "모든");
};
//static 멤버 변수 초기화 필수임.
int Trace::index = 0;
string Trace::tag[MAX_NUMBER] = { " " };
string Trace::info[MAX_NUMBER] = { " " };
void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

void Trace::put(string t, string in) {
	tag[index] = t;
	info[index] = in;
	index++;
}
void Trace::print(string t) {
	if (t == "모든") {
		cout << "---- 모든 Trace 정보를 출력합니다. ----" << endl;
		for (int i = 0; i < index; i++)
			cout << tag[i] << ":" << info[i] << endl;
	}
	else {
		cout << "---- " << t << "태그의 Trace 정보를 출력합니다. ----" << endl;
		for (int i = 0; i < index; i++) {
			if (tag[i] == t) {
				cout << tag[i] << ":" << info[i] << endl;
			}
		}
	}

}

int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}