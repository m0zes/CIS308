#pragma once
class Vector3{
	public:
		void addElem(int);
		int length();
		int dotProduct(Vector3*);
		Vector3(int);
		~Vector3();
		int *vec;
		int size;
	private:
		int curr;
};
