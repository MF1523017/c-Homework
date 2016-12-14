#include"stdafx.h"
#include"russia_1.h"
void Russia_1::Reset(int r,int c)
{
	int i = 0;
	for (auto b:_boxPtrs)
	{
		b->Reset(r + i, c);
		++i;
	}
}
void Russia_1::OnDraw(BlackBoard &board)
{
	for (auto b : _boxPtrs)
	{
		b->OnDraw(board);
	}
}
bool Russia_1::CanMove(int dx, int dy)
{
	for (auto b : _boxPtrs)
	{
		if (!(b->CanMove(dx, dy)))
			return false;
	}
	return true;
	//return _boxPtrs[0]->CanMove(dx, dy) && _boxPtrs[1]->CanMove(dx, dy) && _boxPtrs[2]->CanMove(dx, dy) && _boxPtrs[3]->CanMove(dx, dy);
}
void Russia_1::Move(int dx, int dy)
{
	for (auto b : _boxPtrs)
	{
		b->Move(dx, dy);
	}
}
