#include "stdafx.h"
#include"line.h"
#include"BlackBoard.h"
void Line::draw(BlackBoard &board)const
{
	board.DrawLine(_x1, _y1, _x2, _y2);
}
Figure *LineFactory::createFigure(std::istream &is)
{
	int _x1, _y1, _x2, _y2;
	std::cout << "X1: ";
	is >> _x1;
	std::cout << "Y1: ";
	is >> _y1;
	std::cout << "X2: ";
	is >> _x2;
	std::cout << "Y2: ";
	is >> _y2;
	return new Line(_x1, _y1, _x2, _y2);
}
