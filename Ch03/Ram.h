//Ram.h

class Ram {
	char mem[100 * 1024]; // 100KB�޸�, �� ������ �� ����Ʈ�̹Ƿ� char Ÿ�� ���
	int size;
public:
	Ram(); // mem�迭�� 0���� �ʱ�ȭ�ϰ� size�� 100*1024�� �ʱ�ȭ
	~Ram(); // "�޸� ���ŵ�"���
	char read(int address);
	void write(int address, char value);
};