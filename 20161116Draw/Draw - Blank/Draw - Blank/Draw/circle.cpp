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
Figure *CircleFactory::createFigure()
{
	/*int _x, _y, _radius;
	std::cout << "Center X: ";
	is >> _x;

	std::cout << "Center Y: ";
	is >> _y;

	std::cout << "Radius: ";
	is >> _radius;*/
	return new Circle;
}