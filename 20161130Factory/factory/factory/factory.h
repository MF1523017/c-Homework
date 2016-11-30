#pragma once
#include<iostream>
#include<vector>
class Figure
{
public:
	virtual void draw()const = 0;
};
class Line :public Figure
{
public:
	virtual void draw()const
	{
		std::cout << "draw line" << std::endl;
	}
};
class Circle :public Figure
{
public:
	virtual void draw()const
	{
		std::cout << "draw Circle" << std::endl;
	}

};
class Rectangle :public Figure
{
public:
	virtual void draw()const
	{
		std::cout << "draw Rectangle" << std::endl;
	}

};
//class Factory
//{
//public:
//	Figure * createFigure(int id)
//	{
//		switch (id)
//		{
//		case 1:
//			return new Circle();
//			break;
//		case 2:
//			return new Line();
//			break;
//		default:
//			break;
//		}
//	}
//};
class Factory
{
public:
	virtual Figure * createFigure() = 0;
	virtual int getId()const =0;
};
class LineFactory :public Factory
{
public:
	LineFactory(int id) :_id(id) {};
	virtual Figure * createFigure()
	{
		return new Line();
	}
	virtual int getId()const
	{
		return _id;
	}
private:
	int _id;
};

class CircleFactory :public Factory
{
public:
	CircleFactory(int id) :_id(id) {};
	virtual Figure * createFigure()
	{
		return new Circle();
	}
	virtual int getId()const
	{
		return _id;
	}
private:
	int _id;
};
class RectangleFactory :public Factory
{
public:
	RectangleFactory(int id) :_id(id) {};
	virtual Figure * createFigure()
	{
		return new Rectangle();
	}
	virtual int getId()const
	{
		return _id;
	}
private:
	int _id;
};