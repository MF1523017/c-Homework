#pragma once
#include<memory>
#include<iostream>
#include<iterator>
template<typename T>
class CArray
{
	template<typename T>friend std::ostream& operator<<(std::ostream &os, const CArray<T>  &rhs);
	using Tptr = T*;
private:
	int _arraySize=0;
	int _arrayCapacity=0;
	Tptr _buff;
	CArray &checkCap(int cap);
public:
	
	CArray() :_arraySize(0), _arrayCapacity(0), _buff(nullptr) {};//初始化列表初始化
	CArray(int s, Tptr t, int c=0) {//构造函数
		_arraySize = s;
		_arrayCapacity = 2*s;
		_buff = new T[_arrayCapacity];
		for (int i = 0; i < s; ++i)
			_buff[i] = t[i];
	};
	
#if 0
	//虽然是拷贝构造函数，但是浅复制，无法满足要求
	CArray(const CArray<T> &rhs) :_buff(new T(*rhs._buff)),\
	_arraySize(rhs.size()), \
		_arrayCapacity(rhs.capacity()) {}
#endif
#if 1
	CArray(const CArray<T> &rhs)
	{
		checkCap(rhs.capacity());
		memcpy(_buff, rhs._buff, rhs.size() *sizeof(T));
		_arraySize = rhs.size();
		_arrayCapacity = rhs.capacity();
		//return *this;
	}
#endif
	CArray & operator=(const CArray<T> &rhs);
	T & operator[](const int index);//此版本可被用来赋值
	const T &operator[](const int index)const;
	~CArray() { delete[]_buff; _arrayCapacity = 0; _arraySize = 0; _buff = nullptr; };
	CArray &append(T e);
	int size()const { return _arraySize; };
	int capacity()const { return _arrayCapacity; };
	T & at(int index) { return _buff[index]; };
	CArray& copy(CArray &rhs);
	bool compare(CArray &rhs);
	CArray &insert(int index, T e);
};
//*********************拷贝赋值运算符****************************
#if 1
template<typename T>
CArray<T>& CArray<T>::operator=(const CArray<T> &rhs)
{
	if (this==&rhs)return *this;
	checkCap(rhs.capacity());
	memcpy(_buff, rhs._buff, rhs.size() *sizeof(T));
	_arraySize = rhs.size();
	_arrayCapacity = rhs.capacity();
	return *this;
}
#endif
//*********************下标运算符****************************
template<typename T>
T& CArray<T>:: operator[](const int index)
{
	return _buff[index];
}
template<typename T>
const T& CArray<T>:: operator[](const int index)const
{
	return _buff[index];
}
//********************************************
template<typename T>
std::ostream & operator <<(std::ostream &os, const CArray<T>  &rhs)
{
	for (int i = 0; i < rhs.size(); ++i)
		os << rhs._buff[i] << " ";
	return os;
}
template<typename T>
CArray<T> &CArray<T>::checkCap(int cap)
{
	if (_arrayCapacity > cap)
		return *this;
	else
	{
		_arrayCapacity = 2*cap;
		Tptr tmp_buff = new T[_arrayCapacity];
		_arraySize = _arraySize < _arrayCapacity ? _arraySize : _arrayCapacity;
		memcpy(tmp_buff,_buff, _arraySize *sizeof(T));
		delete[]_buff;
		_buff = tmp_buff;
	}
	return *this;
};
template<typename T>
CArray<T>& CArray<T>::append(T e)
{
	checkCap(_arraySize + 1);
	_buff[_arraySize] = e;
	_arraySize += 1;
	return *this;
};
template<typename T>
CArray<T> &CArray<T>::insert(int index, T e)
{
	checkCap(_arraySize + 1);
	for (int i = _arraySize; i > index; --i)
		_buff[i] = _buff[i - 1];
	_buff[index] = e;
	return *this;
}
template<typename T>
CArray<T>& CArray<T>::copy(CArray &rhs)
{
	checkCap(rhs.capacity());
	memcpy(_buff,rhs._buff, rhs.size() *sizeof(T));
	_arraySize = rhs.size();
	_arrayCapacity = rhs.capacity();
	return *this;
}
template<typename T>
bool CArray<T>::compare(CArray &rhs)
{
	
	if (_arraySize != rhs.size() || _arrayCapacity != rhs.capacity())
		return false;
	return memcmp(_buff, rhs._buff, _arraySize*sizeof(T)) == 0;
#if 0
	for (int i = 0; i < _arraySize; ++i)
	{
		if (_buff[i] != rhs._buff[i])
			return false;
	}
	return true;
#endif
}
