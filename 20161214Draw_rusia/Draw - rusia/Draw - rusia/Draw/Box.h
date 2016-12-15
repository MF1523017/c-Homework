#ifndef __BOX__
#define __BOX__
//#include"UIController.h"

class BlackBoard; 

class Box
{
public:
	const static int BOX_SIZE = 20; 
	
	Box(int left, int top, int r, int c); 

	void Reset(int r, int c)
	{
		_row = r;
		_col = c;
	}

	void OnDraw(BlackBoard &board); 
	
	bool CanMove(int dx, int dy); 
	void Move(int dx, int dy); 
	
	bool LeftTo(int x)
	{
		return _left + _col * BOX_SIZE < x;
	}

	bool RightTo(int x)
	{
		return _left + (_col + 1) * BOX_SIZE - 1 > x; 
	}

	bool LowerTo(int y)
	{
		return _top + (-_row - 1) * BOX_SIZE + 1 < y; 
	}

	int & Row() { return _row; }
	int & Col() { return _col; }
	//int &Left() { return _left; }
	//const int Right()const { return _left + UIController::COLS*Box::BOX_SIZE; }
private:
	int _left, _top; 
	int _row, _col; 

}; 


#endif // #ifndef __BOX__