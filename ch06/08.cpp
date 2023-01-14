#include <iostream>
#include <string>
using namespace std;
#define MAX_NUMBER 1000

class Trace { 
	//���� 9���̶� ����ϳ�
private:
	static int index;
	static string tag[MAX_NUMBER];
	static string info[MAX_NUMBER];
public:
	static void put(string t, string in);
	static void print(string t = "���");
};
//static ��� ���� �ʱ�ȭ �ʼ���.
int Trace::index = 0;
string Trace::tag[MAX_NUMBER] = { " " };
string Trace::info[MAX_NUMBER] = { " " };
void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

void Trace::put(string t, string in) {
	tag[index] = t;
	info[index] = in;
	index++;
}
void Trace::print(string t) {
	if (t == "���") {
		cout << "---- ��� Trace ������ ����մϴ�. ----" << endl;
		for (int i = 0; i < index; i++)
			cout << tag[i] << ":" << info[i] << endl;
	}
	else {
		cout << "---- " << t << "�±��� Trace ������ ����մϴ�. ----" << endl;
		for (int i = 0; i < index; i++) {
			if (tag[i] == t) {
				cout << tag[i] << ":" << info[i] << endl;
			}
		}
	}

}

int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");
	Trace::print();
}