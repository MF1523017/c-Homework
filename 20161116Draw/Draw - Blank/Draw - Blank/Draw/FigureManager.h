#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_
#include<vector>
#include <iostream>
#include"figure.h"
using std::vector;
class BlackBoard; 

class FigureManager
{
public:
	
	static FigureManager &handle()//单例模式
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager类析构函数
    virtual ~FigureManager() { 
		for (vector<shared_ptr<Figure>>::iterator b = _figures.begin(); b != _figures.end(); ++b)
		{
		/*	delete (*b);
			(*b) = nullptr;*/
			//使用智能指针之后，会在程序结束的时候自动释放内存
		}
		for (vector<shared_ptr<FigureFactory>>::iterator b = _facs.begin(); b != _facs.end(); ++b)
		{
		/*	delete (*b);
			(*b) = nullptr;*/
		}
	}
    // FigureManager类接口.
	void input(std::istream &is); 
    void display(BlackBoard &board); 

	void buildFigureFactory(shared_ptr<FigureFactory> tmp)
	{
		_facs.push_back(tmp);
	}
private:

	vector<shared_ptr<Figure>>_figures;
	vector<shared_ptr<FigureFactory>>_facs;

}; // class FigureManager类定义结束.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
