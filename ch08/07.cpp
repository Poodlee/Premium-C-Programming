#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;
protected: //적는것 가져오는 것 적어야 함. 왜냐하면 멤버의 값에 직접적으로 접근하지 못하니까
			//setData는 2개, ROM 생성자 생성시에 배열 넣기, 밑의 mainMemory.write에는 ch 하나씩 넣기
			// getData ->index만 있으면 접근 가능하게
	BaseMemory(int size) { mem = new char[size]; }
	void setData(char x, int index) { mem[index] = x; }
	void setData(char x[], int length) { for (int i = 0; i < length; i++) mem[i] = x[i]; }
	char getData(int index) { return mem[index]; }
};

class ROM : public BaseMemory {
public:
	ROM(int size, char x[], int length) : BaseMemory(size) { setData(x, length); }
	char read(int index) { return getData(index); }
};

class RAM : public BaseMemory {
public:
	RAM(int size) : BaseMemory(size) { ; }
	void write(int index, char data) { setData(data, index); }
	char read(int index) { return getData(index); }
};

int main() {
	char x[5] = { 'h','e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5); //10KB의 ROM 메모리. 배열x로 초기화됨
	RAM mainMemory(1024 * 1024); //1MB의 RAM 메모리

	// 0번지에서 4번지까지 biosROM에서 읽어 mainMemory에 복사
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}