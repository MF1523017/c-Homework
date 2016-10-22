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
	if (isEmpty()) {//空表
		_header = _tail = tmp;
		_header->_prev = nullptr;
		_tail->_next = nullptr;
	}
	else
	{
		_tail->_next = tmp;
		tmp->_prev = _tail;
		_tail = tmp;
		_tail->_next = nullptr;
	}
	_nodeNum++;
}
#if 0
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
#endif
void CPPList::remove(ListPtr current)
{

	if (current == end()|| isEmpty())//空
		return;
	else {//非空
		if (size()==1)//头尾同节点
		{
			delete current;
			_header = _tail = nullptr;
			
		}
		else {//大于一个节点
			if (current == _header)//头节点
			{
				_header = current->_next;
				_header->_prev = nullptr;
				delete current;
			}
			else {
				if (current == _tail)//尾节点
				{
					_tail = current->_prev;
					_tail->_next = nullptr;
					delete current;
				}
				else {//非头非尾节点
					current->_prev->_next = current->_next;
					current->_next->_prev = current->_prev;
					delete current;
					}
				}
			}
		}
	_nodeNum--;
}
void CPPList::insert(ListPtr current, ElementType e)
{
	ListPtr tmp = new ListNode;
	tmp->_value = e;
	if (isEmpty())//空链表
	{
		_tail=_header = tmp;
		_header->_prev = nullptr;
		_header->_next = current;
	}
	else {//非空
		if (current == _header )//头节点
		{
			 _header = tmp;
			_header->_prev = nullptr;
			_header->_next = current;
			
		}
		else {//非头节点
			if (current == end())//尾节点
			{
				append(e);
				delete tmp;
				_nodeNum--;
			}
			else{//非头非尾节点
				current->_prev->_next = tmp;
				tmp->_prev = current->_prev;
				tmp->_next = current;
			}
		}
	}
	_nodeNum++;
}
void CPPList::clear()
{
	ListPtr tmp = _header;
	while (tmp)
	{
		ListPtr current = tmp->_next;//保存下一节点
		delete tmp;
		tmp = current;
	}
	_header = _tail=nullptr;
	_nodeNum = 0;
}