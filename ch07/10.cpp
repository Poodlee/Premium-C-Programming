#include <iostream>
#include <string>
using namespace std;

// ����: int �迭�� ���� �Ҵ�, ������ �Լ�(!,>>,<<,~)
class Statistics {
private:
	int size;
	int* stat;
public:
	Statistics(int size = 0) { this->size = size; this->stat = new int[size]; }
	bool operator !() {
		if (size == 0) return true;
		else return false;
	}
	void operator >> (int& avg) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += stat[i];
		avg = sum / size;
	}
	void operator ~() {
		for (int i = 0; i < size; i++) {
			cout << stat[i] << ' ';
		}
		cout << endl;
	}
	Statistics& operator <<(int x) {
		size++;
		Statistics tmp(size);
		for (int i = 0; i < size - 1; i++)
			tmp.stat[i] = stat[i];
		tmp.stat[size-1] = x;

		delete[] this->stat;
		this->stat = new int[size];
		for (int i = 0; i < size; i++)
			this->stat[i] = tmp.stat[i];
		return *this;
	}
};

int main() {
	Statistics stat;
	if (!stat) cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

	int x[5];
	cout << "5���� ������ �Է��϶�>>";
	for (int i = 0; i < 5; i++) cin >> x[i]; //x[i] ���� �Է�

	for (int i = 0; i < 5; i++) stat << x[i]; // x[i] ���� ��� ��ü�� �����Ѵ�.
	stat << 100 << 200; //100,200�� ��� ��ü�� �����Ѵ�.
	~stat; //��� �����͸� ��� ����Ѵ�.

	int avg;
	stat >> avg; //��� ��ü�κ��� ����� �޴´�.
	cout << "avg =" << avg << endl;
}