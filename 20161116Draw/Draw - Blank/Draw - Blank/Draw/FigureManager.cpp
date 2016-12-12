#include "stdafx.h" 

#include "FigureManager.h"
#include "BlackBoard.h"
#include"figure.h"
#include"line.h"
#include"circle.h"
#include"rectangle.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
	// 1����ӡ�˵������û�ѡ������ͼ��
	// �˵���ʽΪ
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// ���벻Ҫ��std::cin
	// �ñ��������������is���÷�ͬcin

	// 2���û���������(1/2/3/0)ѡ��󣬸��ݲ�ͬ��ͼ�Σ���ʾ����ͼ�εĲ���
	// ����Բ�Ĳ�������ΪԲ��x��y���뾶����˰�����ʾ����������������½��
	cout << "input type(";
	for (auto item : _facs)//c++11 auto 
	{
		cout << (*item).getId() << ": " << (*item).getName() << ",";
	}
	cout << "0 : Quit)";
	int choice;
	while (is>>choice) {//�����int���ͣ�is��������״̬���˳�whileѭ��
		
		//int choice;
		//is >> choice;
		if (choice == 0)
			break;
		for (auto itemF : _facs)
		{
			if (itemF->getId() == choice)
			{
				shared_ptr<Figure> newF (itemF->createFigure());
				newF->input(is);
				_figures.push_back(newF);
			}
		}
		cout << "input type(";
		for (auto item : _facs)
		{
			cout << (*item).getId() << ": " << (*item).getName() << ",";
		}
		cout << "0 : Quit)";
	}
#if 0
	//�򵥹���ģʽ����������չ����չ��ı�ԭ���߼�
	while (1) {
		int choice;
		cout << "input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)";
		is >> choice;
		switch (choice)
		{
		case 1:
			int _x, _y, _radius;
			std::cout << "Center X: ";
			is >> _x;

			std::cout << "Center Y: ";
			is >> _y;

			std::cout << "Radius: ";
			is >> _radius;
			_figures.push_back(new Circle(_x, _y, _radius));
			break;
		case 2:
			int _x1, _y1, _x2, _y2;
			std::cout << "X1: ";
			is >> _x1;
			std::cout << "Y1: ";
			is >> _y1;

			std::cout << "X2: ";
			is >> _x2;
			std::cout << "Y2: ";
			is >> _y2;
			_figures.push_back(new Line(_x1, _y1, _x2, _y2));
			break;
		case 3:
			int _left, _top, _right, _bottom;
			std::cout << "Left: ";
			is >> _left;
			std::cout << "Top: ";
			is >> _top;

			std::cout << "Right: ";
			is >> _right;
			std::cout << "Bottom: ";
			is >> _bottom;
			_figures.push_back(new Rectangle(_left, _top, _right, _bottom));
		default:
			break;
		}
		if (choice == 0)
			break;

#endif
#if 0
		std::cout << "Center X: ";
		is >> _x;

		std::cout << "Center Y: ";
		is >> _y;

		std::cout << "Radius: ";
		is >> _radius;
#endif

		// �߲���Ϊ�˵�1 X��Y���꣬�˵�2 X���ꡢY���ꡣ
#if 0
		std::cout << "X1: ";
		is >> _x1;
		std::cout << "Y1: ";
		is >> _y1;

		std::cout << "X2: ";
		is >> _x2;
		std::cout << "Y2: ";
		is >> _y2;
#endif

		// ���β���Ϊ���϶���x��y�����¶���x��y
#if 0
		std::cout << "Left: ";
		is >> _left;
		std::cout << "Top: ";
		is >> _top;

		std::cout << "Right: ";
		is >> _right;
		std::cout << "Bottom: ";
		is >> _bottom;
#endif

		// 3������ò����󣬽�ͼ�α�������������֮�����

		// 4���ص�1��������ӡ�˵���ֱ���û�ѡ��0���˳�input����

}

void FigureManager::display(BlackBoard &board)
{
	// ������input�������ͼ�����������λ���
   
	for (auto item : _figures)
		(*item).draw(board);
	// ����board�ṩ��DrawCircle��DrawLine������ͼ����������һ��Բ����30,30λ�ã��뾶Ϊ100��Բ
	//board.DrawCircle(30, 30, 100); 

	//// �پ����������Σ��þ������Ͻ�Ϊ(30, 20)�����½�Ϊ��200,300��
	//board.DrawLine(30, 20, 30, 300); 
	//board.DrawLine(30, 300, 200, 300); 
	//board.DrawLine(200, 300, 200, 20); 
	//board.DrawLine(200, 20, 30, 20); 
}

// ������ʵ����ҪһЩ��Ҫ�ĳ�ʼ�����ɷ�����������У�main���������
// ���û�У������
void InitiateFigureManager()
{
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new CircleFactory(1, "Circle")));
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new LineFactory(2, "line")));
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new RectangleFactory(3, "Rectangle")));
}


