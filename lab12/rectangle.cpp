/*
class Rectangle {
        public:
                Rectangle(int, int);
                int area(void);
                void print(void);
        private:
                int width;
                int height;
                friend Square;
};
*/
#include <iostream>
using namespace std;

#include "rectangle.h"
Rectangle::Rectangle(int w, int h) {
	width = w;
	height = h;
}

int Rectangle::area(void) {
	return width*height;
}

void Rectangle::print(void) {
	cout << width << " x " << height << " rectangle" << endl;
}
