#pragma once
#include<iostream>
using ElementType = double;
using ElementPtr = ElementType *;

class Vector
{
	friend Vector operator +(Vector &lhs, ElementType e);
	friend Vector operator -(Vector &lhs, ElementType e);
	friend Vector operator -(Vector & rhs);
	friend Vector operator *(Vector &lhs, ElementType scale);
	friend bool operator ==(const Vector &lhs, const Vector &rhs);
	friend bool operator !=(const Vector &lhs, const Vector &rhs);
	friend Vector  operator +(const Vector &lhs, const Vector &rhs);
	friend Vector  operator -(const Vector &lhs, const Vector &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Vector &rhs);
public:
	static Vector INVALID_VECTOR;
	Vector() :_size(0), _buff(nullptr) {};
	Vector(int len, ElementPtr data);
	Vector(int len, ElementType e);
	Vector(const Vector &rhs);
	Vector & operator=(const Vector &rhs);
	Vector & operator=(ElementType e);
	Vector & operator+=(const Vector &rhs);
	Vector & operator-=(const Vector &rhs);
	
	const ElementType & operator[](int index) const{ return _buff[index]; };
	ElementType & operator[](int index)  { return _buff[index]; };
	int size()const { return _size; }
	~Vector();
	friend class Matrix;
private:
	int _size;
	ElementPtr _buff;
	void _clear();
};
Vector operator +( Vector &lhs,ElementType e);
Vector operator -( Vector &lhs, ElementType e);
Vector operator -(Vector & rhs);
Vector operator +(const Vector &lhs, const Vector &rhs);
Vector operator -(const Vector &lhs, const Vector &rhs);
Vector operator *(Vector &lhs, ElementType scale);
bool operator ==(const Vector &lhs, const Vector &rhs);
bool operator !=(const Vector &lhs, const Vector &rhs);
std::ostream &operator<<(std::ostream &os, const Vector &rhs);