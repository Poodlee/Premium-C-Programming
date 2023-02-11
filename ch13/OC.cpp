#include <iostream>
#include <string>
#include <cctype>	// isdigit
using namespace std;

class HardwareException {
	string step;
	string msg;
public:
	HardwareException(string step = " ", string msg = " ") {
		this->step = step; this->msg = msg;
	}
	string getStep() { return step; }
	string getMsg() { return msg; }
	void setMsg(string msg) { this->msg = msg; }
	void print() {
		cout << step << " ����, " << msg << endl;
	}
};

class CPU {
	string instruction;
	int op1, op2;
	string op1_s, op2_s;
	string cmd;
	void fetch() throw(HardwareException); // ��ɾ Ű����κ��� �о� �´�.
	void decode() throw(HardwareException); // ��ɾ� �ڵ尡 �������� �Ǻ�
	void execute() throw(HardwareException); // ��ɾ� �ڵ忡 ���� ��� ����
public:
	CPU() { ; }
	bool isInt(string x) {
		bool result = true;
		for (int i = 0; i < x.size(); i++) {
			if (isdigit(x[i]) == false) result = false;
		}

		return result;
	}
	void run() {	// fetch() decode() execute()�� ���������� ȣ��
		while (1) {
			try {
				fetch();
				decode();
				execute();
			}
			catch (HardwareException e) {
				e.print();
			}
		}
	}
};

void CPU::fetch() {  // �Է� �ޱ�
	instruction = ""; // �̸� ���� �صα�
	getline(cin, instruction);
	this->instruction = instruction;
	if (instruction == "")
		throw HardwareException("fecth", "��� ���� ����");
}
void CPU::decode() { // ���� �ֳ� Ȯ���ϱ�
	int voidNum = 0;
	for (int i = 0; i < instruction.size(); i++)
		if (instruction[i] == ' ') voidNum += 1;
	
	if (voidNum != 2) {
		throw HardwareException("decode", "�ǿ����� ����");
	}
	// string �ɰ���
	int voidIndex1 = instruction.find(' ');
	int voidIndex2 = instruction.find(' ', voidIndex1 + 1);

	cmd = instruction.substr(0, voidIndex1);
	string op1_s = instruction.substr(voidIndex1 + 1, voidIndex2 - voidIndex1 - 1);
	string op2_s = instruction.substr(voidIndex2 + 1);
	this->cmd = cmd; this->op1_s = op1_s; this->op2_s = op2_s;

	if (cmd == "ADD" || cmd == "SUB" || cmd == "MUL" || cmd == "DIV") {}
	else {
		throw HardwareException("decode", "invalid ��ɾ� ����");
	}
	if (cmd == "DIV" && op2_s == "0")
		throw HardwareException("decdoe", "0���� ������ ����");

	if (isInt(op1_s) == false || isInt(op2_s) == false)   // ������ ������ �� Ȯ���� ���� ���ڷ� �ٲ㼭 �����ؾ� �Ѵ�. 
		throw HardwareException("decode", "�ǿ����� Ÿ�� ����");	// ������ op1_s�� op1���� �ٲ㼭 op1�� ���� ������ ���� 'a'�� ������ abort() ���� �߻�.
}
void CPU::execute() { // ��� ����� ����ϱ�
	this->op1 = stoi(this->op1_s); this->op2 = stoi(this->op2_s);
	if (cmd == "ADD") {
		cout << "              " << "ADD " << op1 << " " << op2 << ":    " << op1 + op2 << endl;
	}
	else if (cmd == "SUB") {
		cout << "              " << "SUB " << op1 << " " << op2 << ":    " << op1 - op2 << endl;
	}
	else if (cmd == "MUL") {
		cout << "              " << "MUL " << op1 << " " << op2 << ":    " << op1 * op2 << endl;
	}
	else if (cmd == "DIV") {
		cout << "              " << "DIV " << op1 << " " << op2 << ":    " << op1 / op2 << endl;
	}
}

int main() {
	CPU DJ_CPU;
	DJ_CPU.run();
}