#pragma once
#include"BlackBoard.h"
#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
class Figure
{
public:
	virtual void draw(BlackBoard &board) const= 0;
};

class FigureFactory
{
public:
	FigureFactory(int id, const string name) :_id(id), _name(name) {};
	virtual const string &getName()const { return _name; };
	virtual const int &getId()const { return _id; }
	virtual Figure *createFigure(std::istream &is) =0;
private:
	int _id;
	string _name;
};
