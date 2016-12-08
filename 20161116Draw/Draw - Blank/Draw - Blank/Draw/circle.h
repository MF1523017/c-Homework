#pragma once
#include"figure.h"

class Circle :public Figure
{
public:
	Circle() = default;
	Circle(int x, int y, int radius) :_x(x), _y(y), _radius(radius) {};
	virtual void draw(BlackBoard &board)const;
	virtual void input(std::istream &is);
	virtual ~Circle()
	{
		std::cout << "delete Circle!" << std::endl;
	}
private:
	int _x;
	int _y;
	int _radius;

};
class CircleFactory :public FigureFactory
{
public:
	CircleFactory(int id, const string &name) :FigureFactory(id, name) {};
	virtual shared_ptr<Figure> createFigure();
	virtual ~CircleFactory()
	{
		std::cout << "delete CircleFactory!" << std::endl;
	}
};