#include"stdafx.h"
#include"russia_4.h"
void Russia_4::Reset(int r, int c)
{
	_boxPtrs[0]->Reset(r+1, c);
	_boxPtrs[1]->Reset(r, c);
	_boxPtrs[2]->Reset(r+2, c );
	_boxPtrs[3]->Reset(r , c-1);
}