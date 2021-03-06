#pragma once
#include"figure.h"

class Rectangle :public Figure
{
public:
	Rectangle() = default;
	Rectangle(int left, int top, int right, int bottom) :_left(left), _top(top), _right(right), _bottom(bottom) {};
	virtual void draw(BlackBoard &board) const;
	virtual void input(std::istream &is);
	virtual ~Rectangle()
	{
		std::cout << "delete Rectangle!" << std::endl;
	}
private:
	int _left;
	int _top;
	int _right;
	int _bottom;
};
class RectangleFactory :public FigureFactory
{
public:
	RectangleFactory(int id, const string &name) :FigureFactory(id, name) {}
	virtual shared_ptr<Figure> createFigure();
	virtual ~RectangleFactory()
	{
		std::cout << "delete RectangleFactory!" << std::endl;
	}
};