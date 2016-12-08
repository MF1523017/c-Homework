#pragma once
#include"figure.h"
class Line:public Figure {
public:
	Line()=default;
	Line(int x1, int y1, int x2, int y2) :_x1(x1), _y1(y1), _x2(x2), _y2(y2) {};
	virtual void draw(BlackBoard &board)const;
	virtual void input(std::istream &is);
	virtual ~Line()
	{
		std::cout << "delete Line!" << std::endl;
	};
private:
	int _x1;
	int _y1;
	int _x2;
	int _y2;

};
class LineFactory :public FigureFactory
{
public:
	LineFactory(int id,const string &name) :FigureFactory(id,name){}
	virtual shared_ptr<Figure> createFigure();
	virtual ~LineFactory()
	{
		std::cout << "delete LineFactory!" << std::endl;
	}
};

