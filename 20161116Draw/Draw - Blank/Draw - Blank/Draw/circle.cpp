#include "stdafx.h"
#include"circle.h"
void Circle::draw(BlackBoard &board)const
{
	board.DrawCircle(_x, _y, _radius);
}
void Circle::input(std::istream &is)
{
	std::cout << "Center X: ";
	is >> _x;

	std::cout << "Center Y: ";
	is >> _y;

	std::cout << "Radius: ";
	is >> _radius;
}
shared_ptr<Figure> CircleFactory::createFigure()
{
	//必须将shared_ptr显式绑定到一个想要返回的指针上
	return shared_ptr<Figure>(new Circle);
}