#include"stdafx.h"
#include"russia_5.h"
void Russia_5::Reset(int r, int c)
{
	_boxPtrs[0]->Reset(r, c);
	_boxPtrs[1]->Reset(r, c + 1);
	_boxPtrs[2]->Reset(r + 1, c);
	_boxPtrs[3]->Reset(r + 2, c);
}