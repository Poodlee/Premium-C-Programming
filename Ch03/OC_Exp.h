// Exp.h

class Exp {
	int base;
	int up;
public:
	Exp();
	Exp(int a);
	Exp(int a, int b);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};