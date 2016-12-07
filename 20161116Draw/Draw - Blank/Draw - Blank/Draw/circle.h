#pragma once
#include"figure.h"

class Circle :public Figure
{
public:
	Circle() = default;
	Circle(int x, int y, int radius) :_x(x), _y(y), _radius(radius) {};
	virtual void draw(BlackBoard &board)const;
	virtual void input(std::istream &is);
private:
	int _x;
	int _y;
	int _radius;

};
class CircleFactory :public FigureFactory
{
public:
	CircleFactory(int id, const string &name) :FigureFactory(id, name) {};
	virtual Figure *createFigure();
};