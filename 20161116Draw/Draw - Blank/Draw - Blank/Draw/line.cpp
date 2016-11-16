#include "stdafx.h"
#include"line.h"
#include"BlackBoard.h"
void Line::draw(BlackBoard &board)const
{
	board.DrawLine(_x1, _y1, _x2, _y2);
}