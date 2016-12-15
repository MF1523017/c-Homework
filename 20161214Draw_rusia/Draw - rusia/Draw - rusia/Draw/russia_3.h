#pragma once
#include"russia.h"
//T×ÖÐÎ
class Russia_3 :public Russia
{
public:
	Russia_3(int left, int top, int row, int col) {
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row ,col-1)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col + 1)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 1, col)));
	}
	virtual void Reset(int r, int c);
};