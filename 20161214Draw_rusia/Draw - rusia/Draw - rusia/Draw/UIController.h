#ifndef __UICONTROLLER__
#define __UICONTROLLER__

#include "Box.h"
#include"russia_1.h"
#include"russia_2.h"
#include"russia_3.h"
#include"russia_4.h"
#include"russia_5.h"
#include"russia_6.h"
#include"russia_7.h"
#include<vector>
#include<iostream>
#include<memory>
#include<cstdlib>
#include<ctime>

class BlackBoard; 

class UIController
{
public:
	// 整个区域容纳的方块数量
	const static int ROWS = 30; 
	const static int COLS = 10;

	// 初始掉落位置
	const static int INITIAL_COL = COLS / 2; 

public:
	// UIController采用单子模式，整个软件中唯一
	static UIController &handle()
	{
		static UIController instance; 
		return instance; 
	}

	// 掉落速度，单位毫秒，即每X毫秒掉落一格
	int GameSpeed() { return 300-(_score/2); }

	// 定时器处理逻辑，此处主要用于驱动方块自动掉落
	void OnTimer(int code); 

	// 绘图逻辑，包括边框绘制，方块绘制
	void OnDraw(BlackBoard &board); 

	// 按键逻辑，主要处理用户左、右、下三个方向的操作
	void OnKey(unsigned char key, int x, int y); 

	// 判断方块是否触碰左边界、右边界、下边界、及已有固定方块
	bool HitLeft(Box &box);
	bool HitRight(Box &box);
	bool HitBottom(Box &box);
	bool HitBoxes(Box &box); 

	~UIController(); 

private:
	UIController(); 
	
	// 删除已满的行
	void EraseFullRows();

	// 删除已满行后，上方方块下落
	void PushRows(int row); 

	// 活动方块控制逻辑
	void MoveBoxLeft(); 
	void MoveBoxRight(); 
	void MoveBoxDown(); 
	void Rotate();
	void Pause();
	void gameOver();
	// 活动方块插入固定方块
	void InsertBox(std::shared_ptr<Russia> russia)
	{
		for(auto b:russia->_boxPtrs){
			_boxes[b->Row()][b->Col()] = true;
			if (b->Row() == 0)
			{
				gameOver();
				break;
				//std::cout << "		play again(y):";
				//unsigned char choice;
				//std::cin >> choice;
				//if (tolower(choice) == 'y') {
				//	for (int r = 0; r < ROWS; ++r)
				//	{
				//		for (int c = 0; c < COLS; ++c)
				//		{
				//			// 初始没有固定方块
				//			_boxes[r][c] = false;
				//		}
				//	}
				//	break;
				//}
				//else
				//{
				//	exit(0);
				//}
			}
		}
	}
private:
	//bool _canMoves();
	void _Reset()
	{
		_russiaPtrs[_random]->Reset(0, INITIAL_COL);
		/*_random += 1;
		_random %= 7;*/
		_random = _next;
		_russiaPtrs[_random]->Reset(0, INITIAL_COL);
		while (true) {
			_next = _rand();//产生随机数
			if (_next != _random)
				break;
		}
		//curRussia = _russiaPtrs[1];
		_russiaPtrs[_next]->Reset(5, 14);
	}
	int _rand()
	{
		 return rand() % 7;
	}
	bool _boxes[ROWS][COLS]; 
	int _left,  _bottom; 
	int _right, _top; 
	int _random;
	int _next;
	int _score;
	//std::shared_ptr<Russia> curRussia;
	typedef std::vector<std::shared_ptr<Russia>> RussiaVecPtr;
	RussiaVecPtr _russiaPtrs;
	
}; 


#endif // #ifndef __UICONTROLLER__