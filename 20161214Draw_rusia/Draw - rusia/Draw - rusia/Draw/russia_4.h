#pragma once
#include"russia.h"
//¡®7¡¯×ÖÍ¼ÐÎ
class Russia_4 :public Russia
{
public:
	Russia_4(int left, int top, int row, int col) {
		/*_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row, col - 1)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row+1, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 2, col)));*/
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 1, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row , col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row + 2, col)));
		_boxPtrs.push_back(std::shared_ptr<Box>(new Box(left, top, row , col-1)));
	}
	virtual void Reset(int r, int c);


};