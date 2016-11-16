#include "stdafx.h"
#include"rectangle.h"

void Rectangle::draw(BlackBoard &board)const
{
	board.DrawLine(_left, _top, _left, _bottom);
	board.DrawLine(_left, _bottom, _right, _bottom);
	board.DrawLine(_right, _bottom, _right, _top);
	board.DrawLine(_right, _top, _left, _top);
}