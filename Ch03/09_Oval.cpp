//Oval.cpp

#include "Oval.h"
#include <iostream>
using namespace std;

Oval::Oval(int w, int h) {
	this->width = w;
	this->height = h;
}
Oval::Oval() {
	this->width = 1;
	this->height = 1;
}
Oval::~Oval() {
	cout << "Oval ¼Ò¸ê : width = " << width << ", height = " << height << endl;
}
int Oval::getWidth() { return width; }
int Oval::getHeight() { return height; }
void Oval::set(int w, int h) {
	this->width = w;
	this->height = h;
}
void Oval::show() {
	cout << "width = " << width << " height = " << height << endl;
}