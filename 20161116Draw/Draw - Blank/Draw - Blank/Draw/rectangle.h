#pragma once
#include"figure.h"

class Rectangle :public Figure
{
public:
	Rectangle(int left, int top, int right, int bottom) :_left(left), _top(top), _right(right), _bottom(bottom) {};
	virtual void draw(BlackBoard &board) const;
private:
	int _left;
	int _top;
	int _right;
	int _bottom;
};