#include"CLibArray.h"
//CArray::CArray(int size,int cap,elementPrt nullptr)
CArray &CArray::checkCap(int cap)
{
	if (arrayCapacity > cap)
		return *this;
	else
	{
		arrayCapacity = cap;
		elementPrt tmpbuff = new elementType[cap];
		arraySize = arraySize < arrayCapacity ? arraySize : arrayCapacity;
		for (int i = 0; i < arraySize; ++i)
			tmpbuff[i] = buff[i];
		delete[]buff;
		buff = tmpbuff;
	}
	return *this;
}
CArray& CArray::append(elementType e)
{
	checkCap(arraySize + 1);
	buff[arraySize] = e;
	arraySize += 1;
	return *this;
}
elementType &CArray::at(int index)
{
	return buff[index];
}
CArray &CArray::insert(int index, elementType e)
{
	checkCap(arraySize + 1);
	for (int i = arraySize; i > index; --i)
		buff[i] = buff[i - 1];
	buff[index] = e;
	return *this;
}
CArray& CArray::copy(CArray &rst)
{
	checkCap(rst.capacity());
	for (int i = 0; i < rst.size(); ++i)
		buff[i] = rst.buff[i];
	arraySize = rst.size();
	arrayCapacity = rst.capacity();
	return *this;
}
bool CArray::compare(CArray &rst)
{
	if (arraySize != rst.size() || arrayCapacity != rst.capacity())
		return false;
	for (int i = 0; i < arraySize; ++i)
	{
		if (buff[i] != rst.buff[i])
			return false;
	}
	return true;
}