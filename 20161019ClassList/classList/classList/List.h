#pragma once
/*
����ΪCPPList
������
	append(value)//��ĩβ׷��һ��Ԫ��
	size()//����list�е�Ԫ�ظ���
	begin()//����list�ĵ�һ��Ԫ��
	end()//������
	next(ListNode * current)//ָ��current��һ��Ԫ��d��ַ
	data()//���ظýڵ������
	remove(ListNode * current)//ɾ���ýڵ�
	insert(ListNode * current,value)//��current ����value
	clear()//ɾ�����нڵ�
��Ա������
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
