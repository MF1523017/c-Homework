#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_
#include<vector>
#include<map>
#include <iostream>
#include"figure.h"
using std::vector;
using std::map;
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
		for (vector<Figure *>::iterator b = _figures.begin(); b != _figures.end(); ++b)
		{
			delete (*b);
			(*b) = nullptr;
		}
		for (vector<FigureFactory *>::iterator b = _facs.begin(); b != _facs.end(); ++b)
		{
			delete (*b);
			(*b) = nullptr;
		}
	}
    // FigureManager��ӿ�.
	void input(std::istream &is); 
    void display(BlackBoard &board); 
	//void setIDName(int id,const string &name)
	//{
	//	_figuresNames.insert(IDName::value_type(id,name));
	//}
	void addFigure(FigureFactory *tmp)
	{
		_facs.push_back(tmp);
	}
private:

	vector<Figure*>_figures;
	vector<FigureFactory*>_facs;
	//typedef map<int, string>IDName;
	//IDName _figuresNames;
}; // class FigureManager�ඨ�����.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
