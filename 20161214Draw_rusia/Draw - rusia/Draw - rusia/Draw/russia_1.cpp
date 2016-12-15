#include"stdafx.h"
#include"russia_1.h"
#include"UIController.h"
void Russia_1::Reset(int r,int c)
{
	int i = 0;
	for (auto b:_boxPtrs)
	{
		b->Reset(r + i, c);
		++i;
	}
}
void Russia_1::Rotate()
{
	if (_boxPtrs[0]->Col() == _boxPtrs[1]->Col())
	{
		int c = _boxPtrs[0]->Col();
		int r = _boxPtrs[0]->Row();
		int i = 0;
		for (auto b : _boxPtrs)
		{
			b->Reset(r , c+i);
			++i;
		}
		if(_boxPtrs[3]->Col()>=UIController::COLS)
			Move(0, UIController::COLS - (_boxPtrs[3]->Col()) - 1);
	}
	else
	{
		int c = _boxPtrs[0]->Col();
		int r = _boxPtrs[0]->Row();
		Reset(r, c);
	}
}
//void Russia_1::OnDraw(BlackBoard &board)
//{
//	for (auto b : _boxPtrs)
//	{
//		b->OnDraw(board);
//	}
//}
//bool Russia_1::CanMove(int dx, int dy)
//{
//	for (auto b : _boxPtrs)
//	{
//		if (!(b->CanMove(dx, dy)))
//			return false;
//	}
//	return true;
//	//return _boxPtrs[0]->CanMove(dx, dy) && _boxPtrs[1]->CanMove(dx, dy) && _boxPtrs[2]->CanMove(dx, dy) && _boxPtrs[3]->CanMove(dx, dy);
//}
//void Russia_1::Move(int dx, int dy)
//{
//	for (auto b : _boxPtrs)
//	{
//		b->Move(dx, dy);
//	}
//}
