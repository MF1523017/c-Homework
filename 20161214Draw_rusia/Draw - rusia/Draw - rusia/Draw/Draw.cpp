// Draw.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "BlackBoard.h"
#include "UIController.h"

// 提供绘图环境的对象
BlackBoard board; 

// 可忽略
void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}


// 定时器回调函数，具体功能逻辑交由UIController处理
void TimerCallback(int value)
{
	UIController::handle().OnTimer(value); 

	// GameSpeed在UIController中，可用于控制难度
	board.InstallTimerCallback(UIController::handle().GameSpeed(), TimerCallback, value); 
}

// 窗口用于处理键盘输入的回调函数入口，具体功能逻辑交由UIController处理
void KeyboardCallback(unsigned char key, int x, int y)
{
	UIController::handle().OnKey(key, x, y); 
}

// 窗口用于绘制的回调函数入口，具体功能逻辑交由UIController处理
void DisplayCallback()
{
	board.Clear(); 

	UIController::handle().OnDraw(board); 
	
	board.Flush(); 
}
//struct  st
//{ 
//	/*static double a;
//	 int b;*/
//};
//double st::a = 0.1;
//double st::b = 0.1;double st::a = 0.1;
int _tmain(int argc, _TCHAR* argv[])
{
	//
	//st s;
	////s.a = 0.2;
	//std::cout << sizeof(st) << std::endl;
	// 以下代码用于初始化窗口等、可忽略
	std::cout << "			TETRIS GAME\n"
		<< "===========================================================\n"
		<< "		Usage:\n"
		<< "		tap a or A to move to left\n"
		<< "		tap d or D to move to right\n"
		<< "		tap s or S to move to down\n"
		<< "		tap w or W to rotate\n"
		<< "===========================================================\n"
		<< "		start game:y  .end game:q\n"
		<< "		your choice:";
	unsigned char choice;
	std::cin >>choice;
	if (tolower(choice) == 'y') {
		board.InitCommandLine(&argc, (char **)argv);
		board.InitWindowSize(600, 800);

		board.InitDisplayCallback(DisplayCallback);
		board.InitKeyboardCallback(KeyboardCallback);
		board.InitReshapeCallback(ReshapeCallback);

		board.InstallTimerCallback(UIController::handle().GameSpeed(), TimerCallback, 0);

		board.Show();
	}
	return 0;
}

