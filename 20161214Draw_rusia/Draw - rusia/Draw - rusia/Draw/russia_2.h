#pragma once

#include"russia.h"
//Russia_1Ìï×Ö¸ñÍ¼ÐÎ
class Russia_2 :public Russia
{
public:
	Russia_2(int left, int top, int row, int col) {
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row , col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row+1, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col+1)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row+1, col+1)));
	}
	virtual void Reset(int r, int c);
	virtual void OnDraw(BlackBoard &board);
	virtual bool CanMove(int dx, int dy);
	virtual void Move(int dx, int dy);
	//virtual int id()const { return _id; };
};
