#pragma once
#include"russia.h"
//Russia_1Ö±ÏßÍ¼ÐÎ
class Russia_1:public Russia
{
public:
	Russia_1(int left,int top,int row,int col) {
		for (int i = 0; i < 4; ++i)
		{
			_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row+i, col)));
		}
	}
	virtual void Reset(int r,int c);
	virtual void Rotate();
	/*virtual void OnDraw(BlackBoard &board);
	virtual bool CanMove(int dx, int dy);
	virtual void Move(int dx, int dy);*/
	//virtual int id()const { return _id; };
};
