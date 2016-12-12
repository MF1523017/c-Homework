#pragma once
#include"BlackBoard.h"
#include<iostream>
#include<vector>
#include<string>
#include<memory>
using std::string;
using std::vector;
using std::shared_ptr;
class Figure
{
public:
	virtual void draw(BlackBoard &board) const= 0;
	virtual void input(std::istream &is)=0;
	virtual ~Figure()//析构函数一般为虚函数，这样在析构的时候
					//就能动态绑定，不会发生派生类的独有的成员变量“被剥离”的情况
					//能够完全释放内存
	{
		std::cout << "delete Figure!" << std::endl;
	};
};

class FigureFactory
{
public:
	FigureFactory(int id, const string name) :_id(id), _name(name) {};
	virtual const string &getName()const { return _name; };
	virtual const int &getId()const { return _id; }
	virtual shared_ptr<Figure> createFigure() =0;
	virtual ~FigureFactory()
	{
		std::cout << "delete FigureFactory!" << std::endl;
	}
private:
	int _id;
	string _name;
};
