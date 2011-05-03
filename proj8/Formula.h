#pragma once
class Formula {
	public:
		virtual void print() = 0;
		virtual void print(int) = 0;
		virtual Formula * derivative() = 0;
		virtual int evaluate(int) = 0;
};
