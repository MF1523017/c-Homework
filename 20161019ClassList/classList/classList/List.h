#pragma once
/*
类名为CPPList
操作：
	append(value)//在末尾追加一个元素
	size()//返回list中的元素个数
	begin()//包含list的第一个元素
	end()//结束符
	next(ListNode * current)//指向current后一个元素d地址
	data()//返回该节点的数据
	remove(ListNode * current)//删除该节点
	insert(ListNode * current,value)//在current 插入value
	clear()//删除所有节点
成员变量：
	ListNode *_header
	ListNode *_tail
	int _NodeNum
*/
using ElementType = int;
struct ListNode; 
using ListPtr = struct  ListNode*;
using constListPtr = const struct ListNode *;
struct ListNode
{
	ElementType _value;
	ListPtr _next;
	const ElementType data()const { return _value; }
	ElementType &data() { return _value; }
};

class CPPList
{
public:
	CPPList() :_header(nullptr), _tail(nullptr), _nodeNum(0) {};
#if 1
	CPPList(const CPPList &rhs) :_nodeNum(0)
	{

		ListPtr tmp= rhs._header;
		while (tmp)
		{
			append(tmp->data());
			tmp = tmp->_next;
		}
		
	}
	CPPList &operator=(const CPPList & rhs);

	~CPPList() { clear(); };
#endif
	void append(ElementType &e);
	int size()const { return _nodeNum; };
	const ListPtr begin()const { return _header; }
	const ListPtr end()const { 
		return nullptr;
	 }
	constListPtr next(constListPtr current)const  { return current->_next; }
	ListPtr next(constListPtr current) { return current->_next; }
	void remove(ListPtr current);
	void insert(ListPtr current, ElementType e);
	void clear();
private:
	ListPtr _header;
	ListPtr _tail;
	int _nodeNum;
	ListPtr _findPre(ListPtr current);
};
