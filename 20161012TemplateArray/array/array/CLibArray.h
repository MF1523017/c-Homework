#pragma once
#include<memory>
#include<iostream>
template<typename T>
class CArray
{
	template<typename T>friend std::ostream& operator<< (std::ostream &os, const CArray<T>  &rst);
	using Tptr = T*;
private:
	int arraySize=0;
	int arrayCapacity=0;
	Tptr buff;
	CArray &checkCap(int cap);
public:
	CArray() :arraySize(0), arrayCapacity(0), buff(nullptr) {};
	CArray(int s, int c, Tptr t) {
		arraySize = s;
		arrayCapacity = c;
		buff = new T[arrayCapacity];
		for (int i = 0; i < s; ++i)
			buff[i] = t[i];
	};
	~CArray() { delete[]buff; arrayCapacity = 0; arraySize = 0; buff = nullptr; };
	CArray &append(T e);
	int size()const { return arraySize; };
	int capacity()const { return arrayCapacity; };
	T & at(int index) { return buff[index]; };
	CArray& copy(CArray &rst);
	bool compare(CArray &rst);
	CArray &insert(int index, T e);
};

template<typename T>
std::ostream & operator <<(std::ostream &os, const CArray<T>  &rst)
{
	for (int i = 0; i < rst.size(); ++i)
		os << rst.buff[i] << " ";
	return os;
}
template<typename T>
CArray<T> &CArray<T>::checkCap(int cap)
{
	if (arrayCapacity > cap)
		return *this;
	else
	{
		arrayCapacity = 2*cap;
		Tptr tmpbuff = new T[arrayCapacity];
		arraySize = arraySize < arrayCapacity ? arraySize : arrayCapacity;
		memcpy(tmpbuff,buff, arraySize *sizeof(T));
		delete[]buff;
		buff = tmpbuff;
	}
	return *this;
};
template<typename T>
CArray<T>& CArray<T>::append(T e)
{
	checkCap(arraySize + 1);
	buff[arraySize] = e;
	arraySize += 1;
	return *this;
};
template<typename T>
CArray<T> &CArray<T>::insert(int index, T e)
{
	checkCap(arraySize + 1);
	for (int i = arraySize; i > index; --i)
		buff[i] = buff[i - 1];
	buff[index] = e;
	return *this;
}
template<typename T>
CArray<T>& CArray<T>::copy(CArray &rst)
{
	checkCap(rst.capacity());
	memcpy(buff,rst.buff, rst.size() *sizeof(T));
	arraySize = rst.size();
	arrayCapacity = rst.capacity();
	return *this;
}
template<typename T>
bool CArray<T>::compare(CArray &rst)
{
	
	if (arraySize != rst.size() || arrayCapacity != rst.capacity())
		return false;
	return memcmp(buff, rst.buff, arraySize*sizeof(T)) == 0;
#if 0
	for (int i = 0; i < arraySize; ++i)
	{
		if (buff[i] != rst.buff[i])
			return false;
	}
	return true;
#endif
}
