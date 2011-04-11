#pragma once
class MyString {
	public:
		char str[100];
		char& operator[](int);
};
istream& operator>>(ostream&, const MyString&);
ostream& operator<<(istream&, MyString&);
