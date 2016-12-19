// Draw.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "BlackBoard.h"
#include "UIController.h"

// �ṩ��ͼ�����Ķ���
BlackBoard board; 

// �ɺ���
void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}


// ��ʱ���ص����������幦���߼�����UIController����
void TimerCallback(int value)
{
	UIController::handle().OnTimer(value); 

	// GameSpeed��UIController�У������ڿ����Ѷ�
	board.InstallTimerCallback(UIController::handle().GameSpeed(), TimerCallback, value); 
}

// �������ڴ����������Ļص�������ڣ����幦���߼�����UIController����
void KeyboardCallback(unsigned char key, int x, int y)
{
	UIController::handle().OnKey(key, x, y); 
}

// �������ڻ��ƵĻص�������ڣ����幦���߼�����UIController����
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
	// ���´������ڳ�ʼ�����ڵȡ��ɺ���
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

