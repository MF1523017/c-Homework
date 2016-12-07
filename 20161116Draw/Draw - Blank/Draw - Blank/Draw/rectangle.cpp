#include "stdafx.h"
#include"rectangle.h"

void Rectangle::draw(BlackBoard &board)const
{
	board.DrawLine(_left, _top, _left, _bottom);
	board.DrawLine(_left, _bottom, _right, _bottom);
	board.DrawLine(_right, _bottom, _right, _top);
	board.DrawLine(_right, _top, _left, _top);
}
void Rectangle::input(std::istream &is)
{
	std::cout << "Left: ";
	is >> _left;
	std::cout << "Top: ";
	is >> _top;

	std::cout << "Right: ";
	is >> _right;
	std::cout << "Bottom: ";
	is >> _bottom;
}
Figure *RectangleFactory::createFigure()
{
	/*int _left, _top, _right, _bottom;
	std::cout << "Left: ";
	is >> _left;
	std::cout << "Top: ";
	is >> _top;

	std::cout << "Right: ";
	is >> _right;
	std::cout << "Bottom: ";
	is >> _bottom;*/
	return new Rectangle;
}