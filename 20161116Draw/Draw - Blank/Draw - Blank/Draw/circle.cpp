#include "stdafx.h"
#include"circle.h"
void Circle::draw(BlackBoard &board)const
{
	board.DrawCircle(_x, _y, _radius);
}