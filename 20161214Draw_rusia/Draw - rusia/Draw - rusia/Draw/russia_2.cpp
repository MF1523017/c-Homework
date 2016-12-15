#include"stdafx.h"
#include"russia_2.h"
void Russia_2::Reset(int r, int c)
{
	_boxPtrs[0]->Reset(r, c);
	_boxPtrs[1]->Reset(r+1, c);
	_boxPtrs[2]->Reset(r, c+1);
	_boxPtrs[3]->Reset(r+1, c+1);
}
//void Russia_2::OnDraw(BlackBoard &board)
//{
//	for (auto b : _boxPtrs)
//	{
//		b->OnDraw(board);
//	}
//}
//bool Russia_2::CanMove(int dx, int dy)
//{
//	for (auto b : _boxPtrs)
//	{
//		if (!(b->CanMove(dx, dy)))
//			return false;
//	}
//	return true;
//	//return _boxPtrs[0]->CanMove(dx, dy) && _boxPtrs[1]->CanMove(dx, dy) && _boxPtrs[2]->CanMove(dx, dy) && _boxPtrs[3]->CanMove(dx, dy);
//}
//void Russia_2::Move(int dx, int dy)
//{
//	for (auto b : _boxPtrs)
//	{
//		b->Move(dx, dy);
//	}
//}
