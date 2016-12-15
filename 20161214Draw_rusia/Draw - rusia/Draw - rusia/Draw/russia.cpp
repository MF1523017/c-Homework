#include"stdafx.h"
#include"russia.h"
#include"UIController.h"
#define _USE_MATH_DEFINES 
#include<math.h>
void Russia::OnDraw(BlackBoard &board)
{
	for (auto b : _boxPtrs)
	{
		b->OnDraw(board);
	}
}
bool Russia::CanMove(int dx, int dy)
{
	for (auto b : _boxPtrs)
	{
		if (!(b->CanMove(dx, dy)))
			return false;
	}
	return true;
	//return _boxPtrs[0]->CanMove(dx, dy) && _boxPtrs[1]->CanMove(dx, dy) && _boxPtrs[2]->CanMove(dx, dy) && _boxPtrs[3]->CanMove(dx, dy);
}
void Russia::Move(int dx, int dy)
{
	for (auto b : _boxPtrs)
	{
		b->Move(dx, dy);
	}
}
void Russia::Rotate()
{
	double rx0 = 0;
	double ry0 = 0;
	for (auto b : _boxPtrs)
	{
		if (b->Col() == 0) {
			Move(0, 1);
			break;
		}
	}
	for(auto b:_boxPtrs)
	{
		rx0 += b->Col();
		ry0 += b->Row();
	}
	rx0 /= 4;
	ry0 /= 4;
	for (auto b : _boxPtrs)
	{
		
		//任意点(x,y)，绕一个坐标点(rx0,ry0)逆时针旋转a角度后的新的坐标设为(x0, y0)
		int tmpcol = b->Col();
		int tmprow = b->Row();
		b->Col() = static_cast<int>((tmpcol - rx0)*cos(-M_PI_2) - (tmprow - ry0)*sin(-M_PI_2) + rx0);
		b->Row() = static_cast<int>((tmpcol - rx0)*sin(-M_PI_2) + (tmprow - ry0)*cos(-M_PI_2) + ry0);
		
	}
	for (auto b : _boxPtrs)
	{
		if (b->Col() <= 0)
		{
			Move(0, -(b->Col()));
			continue;
		}
		if (b->Col() >= UIController::COLS)
		{
			Move(0, UIController::COLS - (b->Col())-1);
			continue;
		}
		//b->LeftTo(b->Left());
	}
}