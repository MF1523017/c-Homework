#include "stdafx.h"
#include <iostream>
#include "UIController.h"
#include "BlackBoard.h"
#include<string>

extern BlackBoard board; 

UIController::UIController() : _left(-(COLS * Box::BOX_SIZE / 2)), _bottom(-ROWS * Box::BOX_SIZE / 2), _right(COLS * Box::BOX_SIZE / 2), _top(ROWS * Box::BOX_SIZE / 2)
{
	_score = 0;//得分置零
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			// 初始没有固定方块
			_boxes[r][c] = false; 
		}
	}
	//初始化不同的俄罗斯方块
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_1(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_2(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_3(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_4(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_5(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_6(_left, _top, 0, INITIAL_COL)));
	_russiaPtrs.push_back(std::shared_ptr<Russia>(new Russia_7(_left, _top, 0, INITIAL_COL)));
	//auto _boxPtrs = _russiaPtrs[0];
	srand((unsigned)time(0));//指定seed为当前系统流逝的时间
	_random =_rand();
	while (true) {
		_next = _rand();//产生随机数
		if (_next != _random)
			break;
	}
	_russiaPtrs[_next]->Reset(4, 14);
	//_random = 0;
	//curRussia = _russiaPtrs[0];
}

UIController::~UIController()
{
}

void UIController::OnDraw(BlackBoard &board) 
{ 
	board.SetColor(1, 0, 1); 
	board.DrawLine(_left,  _top,   _left,  _bottom);
	board.DrawLine(_left,  _top,   _right, _top);
	board.DrawLine(_left,  _bottom,_right, _bottom);
	board.DrawLine(_right, _top,   _right, _bottom);

	board.SetColor(1, 0, 0); 
	/*for(int i=0;i<4;++i)
		_boxPtrs[i]->OnDraw(board);*/
	_russiaPtrs[_random]->OnDraw(board);
	_russiaPtrs[_next]->OnDraw(board);
	//board.DrawString();
	board.SetColor(0, 1, 1); 
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			if (_boxes[r][c])
			{
				// 借助Box类绘制固定方块
				Box box(_left, _top, r, c); 
				box.OnDraw(board); 
			}
		}
	}
}


void UIController::OnTimer(int code)
{
	MoveBoxDown(); 
}

void UIController::OnKey(unsigned char key, int x, int y)
{
	key = tolower(key);
	switch (key)
	{
	case 'q':
		exit(0);
		break; 

	case 's':
		MoveBoxDown(); 
		break; 

	case 'a':
		MoveBoxLeft(); 
		break; 

	case 'd':
		MoveBoxRight(); 
		break; 
	case 'w':
		Rotate();
		break;

	}
}

bool UIController::HitLeft(Box &box)
{
	return box.LeftTo(_left); 
}

bool UIController::HitRight(Box &box)
{
	return box.RightTo(_right); 
}

bool UIController::HitBottom(Box &box)
{
	return box.LowerTo(_bottom); 
}

bool UIController::HitBoxes(Box &box)
{
	return _boxes[box.Row()][box.Col()]; 
}

void UIController::EraseFullRows()
{
	for (int r = 0; r < ROWS; ++r)
	{
		bool fulled = true; 
		for (int c = 0; c < COLS; ++c)
		{
			if (!_boxes[r][c]) 
			{
				// 任意一个位置无固定方块，则满行条件不满足，跳过
				fulled = false; 
				break; 
			}
		}

		if (fulled)
		{
			PushRows(r); 
			_score += 10;
			std::cout << "you score is " << _score <<std::endl;
		}
	}
}

void UIController::PushRows(int row)
{
	for (int r = row; r > 0; --r)
	{
		for (int c = 0; c < COLS; ++c)
		{
			// row行之上方块下落
			_boxes[r][c] = _boxes[r - 1][c]; 
		}
	}

	for (int c = 0; c < COLS; ++c)
	{
		// 最顶层一行置空
		_boxes[0][c] = false; 
	}
}
void UIController::Rotate()
{
	_russiaPtrs[_random]->Rotate();
}
void UIController::MoveBoxLeft()
{
	//if (_boxPtrs[0]->CanMove(0, -1)&&_boxPtrs[1]->CanMove(0, -1)&& _boxPtrs[2]->CanMove(0, -1)&& _boxPtrs[3]->CanMove(0, -1))
	//{
	//	for (int i = 0; i<4; ++i)
	//		_boxPtrs[i]->Move(0, -1);
	//	//_box.Move(0, -1); 
	//	board.Update(); 
	//}
	if (_russiaPtrs[_random]->CanMove(0, -1))
	{
		_russiaPtrs[_random]->Move(0, -1);
		board.Update();
	}
}

void UIController::MoveBoxRight()
{
	//if (_boxPtrs[0]->CanMove(0, 1) && _boxPtrs[1]->CanMove(0, 1) && _boxPtrs[2]->CanMove(0, 1) && _boxPtrs[3]->CanMove(0, 1))
	//{
	//	for (int i = 0; i<4; ++i)
	//		_boxPtrs[i]->Move(0, 1);
	//	//_box.Move(0, -1); 
	//	board.Update();
	//}
	/*if (_box.CanMove(0, 1))
	{
		_box.Move(0, 1); 
		board.Update(); 
	}*/
	if (_russiaPtrs[_random]->CanMove(0, 1))
	{
		_russiaPtrs[_random]->Move(0, 1);
		board.Update();
	}
}

void UIController::MoveBoxDown()
{
	/*if (_box.CanMove(1, 0))
	{
		_box.Move(1, 0); 
		board.Update(); 
	}*/
	//
	if (_russiaPtrs[_random]->CanMove(1, 0))
	{
		_russiaPtrs[_random]->Move(1, 0);
		board.Update();
	}
	else
	{
		// 无法下移，则说明下方有障碍（边界或固定方块），则活动方块插入固定方块中
		//InsertBox(_box);
		/*for (int i = 0; i<4; ++i)
			_boxes[_boxPtrs[i]->Row()][_boxPtrs[i]->Col()] = true;*/
		InsertBox(_russiaPtrs[_random]);
		// 清楚满行
		EraseFullRows(); 

		// 活动方块重置，相当于新生成一个新的活动方块
		/*for (int i = 0; i < 4; ++i) {
			_boxPtrs[i]->Reset(i, INITIAL_COL);
		}*/
		//_russiaPtrs[0]->Reset(0, INITIAL_COL);
		_Reset();
		//_box.Reset(0, INITIAL_COL); 
		//_box.Reset(0, INITIAL_COL);
		board.Update(); 
	}
}