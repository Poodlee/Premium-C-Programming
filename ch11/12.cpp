#include <iostream>
#include <iomanip>
using namespace std;

class Material { // ��� ������� �ؼ� �ϳ��� Ŭ������ ǥ���ϱ�
protected:  // �ʿ� ����: �̸��� ��
    string name;
    int amount;
public:     // �̸��� �� ���� �� ���
    string getName() {
        return name;
    }
    int getAmount() {
        return amount;
    }
    void setAmount(int amount) {
        this->amount = amount;
    }
    bool subAmount(int amount) {
        if (this->amount <= 0)
            return false;
        else
            this->amount -= amount;
        return true;
    }
};

class Coffee : public Material {
public:
    Coffee() {
        name = "Coffee";
        amount = 3;
    }
};

class Sugar : public Material {
public:
    Sugar() {
        name = "Sugar";
        amount = 3;
    }
};

class Cream : public Material {
public:
    Cream() {
        name = "Cream";
        amount = 3;
    }
};

class Water : public Material {
public:
    Water() {
        name = "Water";
        amount = 3;
    }
};

class Cup : public Material {
public:
    Cup() {
        name = "Cup";
        amount = 3;
    }
};

class CoffeeMachine { //������,���� ��Ȳ ���, �޴� ���, ���ҽ�Ű��, ä���, ���������� run �Լ�
private: // ���� ���� ��ü���� �迭�� �ҷ��;� �Ѵ�. ���� �Ҵ�
    Material *mat[5];
    void show() {
        for (int i = 0; i < 5; i++) {
            cout << setw(10) << mat[i]->getName(); 
            for (int j = 0; j < mat[i]->getAmount(); j++)
                cout << "*";
            cout << endl;
        }
    }
    void menu() {
        cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
    }
    void sell(int n) {
        if (n == 0) {
            if (mat[0]->subAmount(1) == true && mat[2]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                show();
            }
            else
                cout << "��ᰡ �����մϴ�. �ٽ� ä��Ƿ��� �޴����� 3���� �����ּ���." << endl;
        }
        else if (n == 1) {
            if (mat[0]->subAmount(1) == true && mat[1]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << endl;
                show();
            }
            else
                cout << "��ᰡ �����մϴ�. �ٽ� ä��Ƿ��� �޴����� 3���� �����ּ���." << endl;
        }
        else if (n == 2) {
            if (mat[0]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << endl;
                show();
            }
            else
                cout << "��ᰡ �����մϴ�. �ٽ� ä��Ƿ��� �޴����� 3���� �����ּ���." << endl;
        }
    }
    void refill() {
        for (int i = 0; i < 5; i++) {
            mat[i]->setAmount(3);
        }
        cout << "��� ���� ä��ϴ�~~" << endl;
        show();
        cout << endl;
    }

public:
    CoffeeMachine() {
        cout << "-----��ǰ Ŀ�� ���Ǳ� �մϴ�.-----" << endl;
        mat[0] = new Coffee();
        mat[1] = new Sugar();
        mat[2] = new Cream();
        mat[3] = new Water();
        mat[4] = new Cup();
        show();
        cout << endl;
    }
    void run() {
        int choice=0;
        while (1) {
            menu();
            cin >> choice;
            switch (choice) {
            case 0: sell(0); break;
            case 1: sell(1); break;
            case 2: sell(2); break;
            case 3: refill(); break;
            case 4: return;
            }
        }
    }
};

int main() {
    cout.setf(ios::left);
    CoffeeMachine DJ_CoffeMachine;
    DJ_CoffeMachine.run();
}