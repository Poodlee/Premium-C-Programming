#include <iostream>
using namespace std;

int main() {
	int ch, cnt = 0; //ch: 끝이 되면 -1 반환하니까 int
	while ((ch = cin.get()) != EOF) {
		if (ch == '\n') break;
		if (ch == 'a') cnt++;
	}
	cout << "a의 개수는 " << cnt << endl;
}