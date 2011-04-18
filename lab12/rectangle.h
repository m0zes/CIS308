#pragma once
//#include <iostream>
//using namespace std;
class Rectangle {
	public:
		Rectangle(int, int);
		int area(void);
		void print(void);
	private:
		int width;
		int height;
		friend class Square;
};
