#include <iostream>

using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0; //src�� �ٸ� ������ ��ȯ�Ѵ�.
	virtual string getSourceString() = 0; //src ���� ��Ī
	virtual string getDestString() = 0; //dest ���� ��Ī
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ���: " << convert(src) << getDestString() << endl;
	}
};

class kmToMile : public Converter {
public:
	kmToMile(double ratio = 0.0) : Converter(ratio) { }
	double convert(double src) { return src / ratio; }
	string getSourceString() { return "Km"; }
	string getDestString() { return "Mile"; }
};

int main() {
	kmToMile toMile(1.609344); // 1mile = 1.609344km
	toMile.run();

	return 0;
}