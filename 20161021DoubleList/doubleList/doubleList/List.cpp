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
	if (isEmpty()) {//�ձ�
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

	if (current == end()|| isEmpty())//��
		return;
	else {//�ǿ�
		if (size()==1)//ͷβͬ�ڵ�
		{
			delete current;
			_header = _tail = nullptr;
			
		}
		else {//����һ���ڵ�
			if (current == _header)//ͷ�ڵ�
			{
				_header = current->_next;
				_header->_prev = nullptr;
				delete current;
			}
			else {
				if (current == _tail)//β�ڵ�
				{
					_tail = current->_prev;
					_tail->_next = nullptr;
					delete current;
				}
				else {//��ͷ��β�ڵ�
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
	if (isEmpty())//������
	{
		_tail=_header = tmp;
		_header->_prev = nullptr;
		_header->_next = current;
	}
	else {//�ǿ�
		if (current == _header )//ͷ�ڵ�
		{
			 _header = tmp;
			_header->_prev = nullptr;
			_header->_next = current;
			
		}
		else {//��ͷ�ڵ�
			if (current == end())//β�ڵ�
			{
				append(e);
				delete tmp;
				_nodeNum--;
			}
			else{//��ͷ��β�ڵ�
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
		ListPtr current = tmp->_next;//������һ�ڵ�
		delete tmp;
		tmp = current;
	}
	_header = _tail=nullptr;
	_nodeNum = 0;
}