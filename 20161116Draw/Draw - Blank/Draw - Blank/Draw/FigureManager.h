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
	
	static FigureManager &handle()//����ģʽ
	{
		static FigureManager manager; 
		return manager; 
	}
    
    // FigureManager����������
    virtual ~FigureManager() { 
		for (vector<shared_ptr<Figure>>::iterator b = _figures.begin(); b != _figures.end(); ++b)
		{
		/*	delete (*b);
			(*b) = nullptr;*/
			//ʹ������ָ��֮�󣬻��ڳ��������ʱ���Զ��ͷ��ڴ�
		}
		for (vector<shared_ptr<FigureFactory>>::iterator b = _facs.begin(); b != _facs.end(); ++b)
		{
		/*	delete (*b);
			(*b) = nullptr;*/
		}
	}
    // FigureManager��ӿ�.
	void input(std::istream &is); 
    void display(BlackBoard &board); 

	void buildFigureFactory(shared_ptr<FigureFactory> tmp)
	{
		_facs.push_back(tmp);
	}
private:

	vector<shared_ptr<Figure>>_figures;
	vector<shared_ptr<FigureFactory>>_facs;

}; // class FigureManager�ඨ�����.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
