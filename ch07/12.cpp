#include <iostream>
#include <string>
using namespace std;

// ���� �迭�� �׻� ���� ������ ����.  (Ŭ���� �ۼ� �� + = ������ �ߺ� �ۼ�)
class SortedArray {
private:
	int size; //���� �迭�� ũ��
	int* p; //���� �迭�� ���� ������
	void sort(); // ���� �迭�� ������������ ����
public:
	SortedArray(); //p�� NULL�� size�� 0���� �ʱ�ȭ
	SortedArray(const SortedArray& sor); //���� ������
	SortedArray(int p[], int size); // ������. ���� �迭�� ũ�⸦ ���� ����
	~SortedArray() { delete[] p;} // �Ҹ���
	SortedArray operator + (SortedArray& op2); // ���� �迭�� op2 �迭 �߰�
	//SortedArray& operator = (const SortedArray& op2); // ���� �迭�� op2 �迭 ����
	void show();
};
void SortedArray::sort() {
	int tmp; //�̵� ���ؼ�
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size -i-1; j++) {
			if (p[j] > p[j+1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}                           
SortedArray::SortedArray() {
	this->size = 0;
	this->p = NULL;
}
SortedArray::SortedArray(const SortedArray& sor) {
	this->size = sor.size;
	this->p = new int[size];
	for (int i = 0; i < sor.size; i++) {
		this->p[i] = sor.p[i];
	}
}
SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int [size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
	sort();
}
SortedArray SortedArray::operator + (SortedArray& op2) { //���ϰ� ����
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];
	int ind = 0;
	for (int i = 0; i < this->size; i++) {
		tmp.p[ind++] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++) {
		tmp.p[ind++] = op2.p[i];
	}
	tmp.sort();
	return tmp;
}
/*
SortedArray& SortedArray::operator = (const SortedArray& op2) { // ����
	delete[] this->p; //������ �� ����
	this->size = op2.size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = op2.p[i];
	}
	sort();
	return *this;
}
*/
void SortedArray::show() {
	cout << "�迭 ��� : ";
	for (int i = 0; i < size; i++)
		cout << p[i] << ' ';
	cout << endl;
}
int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4);

	SortedArray c = a + b;
	// c = a + b; // +, = �ۼ� �ʿ�
	// + �����ڰ� SortedArray ��ü�� �����ϹǷ� ���� ������ �ʿ�
	a.show();
	b.show();
	c.show();
	
}