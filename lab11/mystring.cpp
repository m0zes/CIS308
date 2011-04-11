#include "mystring.h"
ostream& operator<<(ostream &output, const MyString &m) {
	return output << m.str;
}
istream& operator>>(istream &input, MyString &m) {
	input >> m.str;
	return input;
}
char& MyString::operator[](int index) {
	return str[index];
}
