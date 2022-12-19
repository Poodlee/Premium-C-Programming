// Oval.h

class Oval {
public:
	int width, height;
	Oval(int w, int h);
	Oval();
	~Oval();
	void show();
	int getWidth();
	int getHeight();
	void set(int w, int h);
};