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
	// �����������ɵķ�������
	const static int ROWS = 30; 
	const static int COLS = 10;

	// ��ʼ����λ��
	const static int INITIAL_COL = COLS / 2; 

public:
	// UIController���õ���ģʽ�����������Ψһ
	static UIController &handle()
	{
		static UIController instance; 
		return instance; 
	}

	// �����ٶȣ���λ���룬��ÿX�������һ��
	int GameSpeed() { return 300-(_score/2); }

	// ��ʱ�������߼����˴���Ҫ�������������Զ�����
	void OnTimer(int code); 

	// ��ͼ�߼��������߿���ƣ��������
	void OnDraw(BlackBoard &board); 

	// �����߼�����Ҫ�����û����ҡ�����������Ĳ���
	void OnKey(unsigned char key, int x, int y); 

	// �жϷ����Ƿ�����߽硢�ұ߽硢�±߽硢�����й̶�����
	bool HitLeft(Box &box);
	bool HitRight(Box &box);
	bool HitBottom(Box &box);
	bool HitBoxes(Box &box); 

	~UIController(); 

private:
	UIController(); 
	
	// ɾ����������
	void EraseFullRows();

	// ɾ�������к��Ϸ���������
	void PushRows(int row); 

	// ���������߼�
	void MoveBoxLeft(); 
	void MoveBoxRight(); 
	void MoveBoxDown(); 
	void Rotate();
	// ��������̶�����
	void InsertBox(std::shared_ptr<Russia> russia)
	{
		for(auto b:russia->_boxPtrs)
			_boxes[b->Row()][b->Col()] = true; 
	}
private:
	//bool _canMoves();
	void _Reset()
	{
		_russiaPtrs[_random]->Reset(0, INITIAL_COL);
		/*_random += 1;
		_random %= 7;*/
		_rand();//���������
		//curRussia = _russiaPtrs[1];
	}
	void _rand()
	{
		_random = rand() % 7;
	}
	bool _boxes[ROWS][COLS]; 
	int _left,  _bottom; 
	int _right, _top; 
	int _random;
	int _score;
	//std::shared_ptr<Russia> curRussia;
	typedef std::vector<std::shared_ptr<Russia>> RussiaVecPtr;
	RussiaVecPtr _russiaPtrs;
	
}; 


#endif // #ifndef __UICONTROLLER__