#include"List.h"
#if 1
CPPList &CPPList::operator=(const CPPList & rhs)
{
	if (this == &rhs)return *this;
	clear();
	ListPtr tmp = rhs._header;
	while (tmp)
	{
		append(tmp->data());
		tmp = tmp->_next;
	}
	return *this;
}
#endif
void CPPList::append(ElementType &e)
{
	ListPtr tmp = new ListNode;
	tmp->_value = e;
	if (_nodeNum == 0) {//空表
		_header = _tail= tmp;
		_tail->_next = nullptr;
	}
	else
	{
		_tail->_next = tmp;
		_tail = tmp;
		_tail->_next = nullptr;
	}
	_nodeNum++;
}
ListPtr CPPList::_findPre(ListPtr current)
{
	ListPtr tmp = _header;
	while (tmp)
	{
		if (tmp->_next == current)
		{
			return tmp;
		}
		tmp = tmp->_next;
	}
	return nullptr;
}

void CPPList::remove(ListPtr current)
{
	if (current == _header)//删除头节点
	{
		_header = current->_next;
		delete current;
		_nodeNum--;
	}
	else {
		ListPtr currentPre = _findPre(current);//找出current节点前的节点
		if (currentPre &&currentPre->_next) {
			if (current == _tail)//处理尾部节点情况
			{
				_tail = currentPre;
			}
			currentPre->_next = current->_next;
			delete current;
			_nodeNum--;
		}
	}
	
}
void CPPList::insert(ListPtr current, ElementType e)
{
	ListPtr tmp = new ListNode;
	tmp->_value = e;
	if (_nodeNum==0)//空链表
	{ 
		_header = _tail = tmp;
		_tail->_next = nullptr;
		_nodeNum++;
	}
	else {//非空
		if (current == _header)//在头节点之前插入
		{
			tmp->_next = _header;
			_header = tmp;
			_nodeNum++;
		}
		else {//其他地方插入
			if (current == _tail->_next)//处理尾部节点情况
			{
				_tail->_next = tmp;
				_tail = tmp;
				_tail->_next = nullptr;
			}
			ListPtr currentPre = _findPre(current);
			currentPre->_next = tmp;
			tmp->_next = current;
			_nodeNum++;
		}
	}
}
void CPPList::clear()
{
	ListPtr tmp = _header;
	while (tmp)
	{
		ListPtr current = tmp->_next;
		delete tmp;
		tmp = current;
	}
	_header = _tail=nullptr;
	_nodeNum = 0;
}