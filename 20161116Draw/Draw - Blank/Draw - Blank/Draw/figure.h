#pragma once
#include"BlackBoard.h"
class Figure
{
public:
	virtual void draw(BlackBoard &board) const= 0;
};
