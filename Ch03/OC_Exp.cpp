//Exp.cpp

#include "OC_Exp.h"

Exp::Exp() { base = 1; up = 1; }
Exp::Exp(int a) { base = a; up = 1; }
Exp::Exp(int a, int b) { base = a; up = b; }

int Exp::getValue() {
	int result = base;
	for (int i = 1; i < up; i++)
		result *= base;
	return result;
}

int Exp::getBase() {
	return base;
}
int Exp::getExp() {
	return up;
}
bool Exp::equals(Exp b) {
	if (getValue() == b.getValue())
		return true;
	else return false;
};