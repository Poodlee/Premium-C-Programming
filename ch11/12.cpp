#include <iostream>
#include <iomanip>
using namespace std;

class Material { // 묶어서 상속으로 해서 하나의 클래스로 표현하기
protected:  // 필요 변수: 이름과 양
    string name;
    int amount;
public:     // 이름과 양 설정 및 출력
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

class CoffeeMachine { //생성자,현재 상황 출력, 메뉴 출력, 감소시키기, 채우기, 최종적으로 run 함수
private: // 위의 새부 객체들을 배열로 불러와야 한다. 동적 할당
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
        cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>> ";
    }
    void sell(int n) {
        if (n == 0) {
            if (mat[0]->subAmount(1) == true && mat[2]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "맛있는 보통 커피 나왔습니다~~" << endl;
                show();
            }
            else
                cout << "재료가 부족합니다. 다시 채우실려면 메뉴에서 3번을 눌러주세요." << endl;
        }
        else if (n == 1) {
            if (mat[0]->subAmount(1) == true && mat[1]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
                show();
            }
            else
                cout << "재료가 부족합니다. 다시 채우실려면 메뉴에서 3번을 눌러주세요." << endl;
        }
        else if (n == 2) {
            if (mat[0]->subAmount(1) == true && mat[3]->subAmount(1) == true && mat[4]->subAmount(1) == true) {
                cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
                show();
            }
            else
                cout << "재료가 부족합니다. 다시 채우실려면 메뉴에서 3번을 눌러주세요." << endl;
        }
    }
    void refill() {
        for (int i = 0; i < 5; i++) {
            mat[i]->setAmount(3);
        }
        cout << "모든 통을 채웁니다~~" << endl;
        show();
        cout << endl;
    }

public:
    CoffeeMachine() {
        cout << "-----명품 커피 자판기 켭니다.-----" << endl;
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