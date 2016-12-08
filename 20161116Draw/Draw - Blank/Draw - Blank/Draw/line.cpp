#include "stdafx.h"
#include"line.h"
#include"BlackBoard.h"
void Line::draw(BlackBoard &board)const
{
	board.DrawLine(_x1, _y1, _x2, _y2);
}
void Line::input(std::istream &is)
{
	std::cout << "X1: ";
	is >> _x1;
	std::cout << "Y1: ";
	is >> _y1;
	std::cout << "X2: ";
	is >> _x2;
	std::cout << "Y2: ";
	is >> _y2;
}
shared_ptr<Figure> LineFactory::createFigure()
{
	//必须将shared_ptr显式绑定到一个想要返回的指针上
	return shared_ptr<Figure>(new Line);
}
