#ifndef CLIBARRAY_H
#define CLIBARRAY_H

using elementType = int;
using elementPrt =elementType *;
class CArray
{

private:
	int arraySize;
	int arrayCapacity;
	elementPrt buff;
	CArray &checkCap(int cap);
public:
	
	CArray():arraySize(0),arrayCapacity(0),buff(nullptr) {};
	~CArray() { delete[]buff; arrayCapacity = 0; arraySize = 0; buff = nullptr; };
	CArray &append(elementType e);
	int size()const { return arraySize; };
	int capacity()const { return arrayCapacity; };
	elementType & at(int index)const;
	CArray& copy(CArray &rst);
	bool compare(CArray &rst);
	CArray &insert(int index, elementType e);
};
#endif // !

