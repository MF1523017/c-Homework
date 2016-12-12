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
	// 1、打印菜单，让用户选择输入图形
	// 菜单格式为
	// input type(1 : Circle, 2 : Line, 3 : Rectangle, 0 : Quit)

	// 输入不要用std::cin
	// 用本函数的输入参数is，用法同cin

	// 2、用户输入数字(1/2/3/0)选择后，根据不同的图形，提示输入图形的参数
	// 其中圆的参数依次为圆心x、y、半径，因此包含提示的输入代码类似以下结果
	cout << "input type(";
	for (auto item : _facs)//c++11 auto 
	{
		cout << (*item).getId() << ": " << (*item).getName() << ",";
	}
	cout << "0 : Quit)";
	int choice;
	while (is>>choice) {//输入非int类型，is会进入错误状态，退出while循环
		
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
	//简单工厂模式，不利于拓展，拓展会改变原有逻辑
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

		// 线参数为端点1 X、Y坐标，端点2 X坐标、Y坐标。
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

		// 矩形参数为左上顶点x、y，右下顶点x、y
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

		// 3，输入好参数后，将图形保存下来，用于之后绘制

		// 4，回到1，继续打印菜单，直到用户选择0，退出input函数

}

void FigureManager::display(BlackBoard &board)
{
	// 将所有input中输入的图形在这里依次画出
   
	for (auto item : _figures)
		(*item).draw(board);
	// 借助board提供的DrawCircle和DrawLine函数画图，举例，画一个圆心在30,30位置，半径为100的圆
	//board.DrawCircle(30, 30, 100); 

	//// 再举例，画矩形，该矩形左上角为(30, 20)，右下角为（200,300）
	//board.DrawLine(30, 20, 30, 300); 
	//board.DrawLine(30, 300, 200, 300); 
	//board.DrawLine(200, 300, 200, 20); 
	//board.DrawLine(200, 20, 30, 20); 
}

// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
// 如果没有，则忽略
void InitiateFigureManager()
{
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new CircleFactory(1, "Circle")));
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new LineFactory(2, "line")));
	FigureManager::handle().buildFigureFactory(shared_ptr<FigureFactory>(new RectangleFactory(3, "Rectangle")));
}


