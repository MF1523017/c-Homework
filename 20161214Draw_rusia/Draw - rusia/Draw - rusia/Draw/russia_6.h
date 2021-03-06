#pragma once
#include"russia.h"
class Russia_6 :public Russia
{
public:
	Russia_6(int left, int top, int row, int col) {
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col - 1)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 1, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 1, col+1)));
	}
	virtual void Reset(int r, int c);
};