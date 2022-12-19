//Ram.h

class Ram {
	char mem[100 * 1024]; // 100KB메모리, 한 번지는 한 바이트이므로 char 타입 사용
	int size;
public:
	Ram(); // mem배열을 0으로 초기화하고 size를 100*1024로 초기화
	~Ram(); // "메모리 제거됨"출력
	char read(int address);
	void write(int address, char value);
};