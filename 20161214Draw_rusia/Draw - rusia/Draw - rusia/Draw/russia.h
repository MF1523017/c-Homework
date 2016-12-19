#pragma once
#include"Box.h"
#include<vector>
#include<memory>
class Russia
{
	friend class UIController;
public:
	//Russia()=default;
	virtual void Reset(int r,int c)=0;
	virtual void Rotate();
	virtual void OnDraw(BlackBoard &board);
	virtual bool CanMove(int dx,int dy) ;
	virtual void Move(int dx, int dy);
	//virtual int id()const { return _id; };
protected:
	//int _id;
	typedef std::vector<std::shared_ptr<Box>> vecBoxPtr;
	vecBoxPtr _boxPtrs;
	//int i;
	
};

