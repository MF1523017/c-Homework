#include"factory.h"

int main(int arg,char **argv) {
	//简单工厂模式
	//Factory pf = Factory();
	//int id;
	//std::cin >> id;
	//std::vector<Figure *> vf;
	//vf.push_back(pf.createFigure(id));
	std::vector<Factory *>_facs;
	//建工厂,当新的图形需要增加的时候，只需要创建新图形的工厂和新的图形，整个逻辑不用修改，高拓展性，但同时增加了大大的代码量，
	//但这些代码量也更加便于维护
	_facs.push_back(new LineFactory(2));
	_facs.push_back(new CircleFactory(1));
	_facs.push_back(new RectangleFactory(3));

	int id;
	std::vector<Figure *>_vf;
	while (std::cin >> id)
	{
		for (std::vector<Factory*>::iterator b = _facs.begin(); b != _facs.end(); ++b)
		{
			if ((*b)->getId() == id)//根据ID 来使用不同的工厂来生产不同的图形
			{
				_vf.push_back((*b)->createFigure());
			}
		}
	}
	for (std::vector<Figure*>::iterator b = _vf.begin(); b != _vf.end(); ++b)
	{
		(*b)->draw();
	}

	return 0;
}