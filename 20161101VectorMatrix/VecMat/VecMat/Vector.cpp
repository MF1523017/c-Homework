#include"Vector.h"
#include<memory>
Vector Vector::INVALID_VECTOR = Vector();
std::ostream & operator<<( std::ostream &os, const Vector &rhs)
{
	for (int i = 0; i < rhs.size(); ++i)
		os << rhs._buff[i] << " ";
	return os;
}
Vector::Vector(int len, ElementPtr data):_size(len)
{
	_buff = new ElementType[len];
	for (int i = 0; i < len; ++i)
		_buff[i] = data[i];
}
Vector::Vector(int len, ElementType e) : _size(len)
{
	_buff = new ElementType[len];
	for (int i = 0; i < size(); ++i)
		_buff[i] = e;
}

Vector::Vector(const Vector &rhs)
{
	*this = rhs;
}
Vector & Vector::operator=(ElementType e)
{
	for (int i = 0; i < size(); ++i)
		_buff[i] = e;
	return *this;
}
Vector & Vector::operator=(const Vector &rhs)
{
	if (this == &rhs) return *this;
	_clear();
	_size = rhs._size;
	_buff = new ElementType[size()];
	memcpy(_buff, rhs._buff, sizeof(ElementType)*size());
	return *this;
}
Vector &Vector::operator+=(const Vector &rhs)
{
	for (int i = 0; i < size(); ++i)
		_buff[i] += rhs._buff[i];
	return *this;
}
Vector &Vector::operator-=(const Vector &rhs)
{
	for (int i = 0; i < size(); ++i)
		_buff[i] -= rhs._buff[i];
	return *this;
}
Vector  operator +(const Vector &lhs, const Vector &rhs)
{
	if (lhs.size() != rhs.size())
		return Vector();
	ElementPtr buff = new ElementType[lhs.size()];
	for (int i = 0; i < lhs.size(); ++i)
		buff[i] = lhs._buff[i] + rhs._buff[i];
	return Vector(lhs.size(), buff);
}
Vector operator -(const Vector &lhs, const Vector &rhs)
{
	if (lhs.size() != rhs.size())
		return Vector();
	ElementPtr buff = new ElementType[lhs.size()];
	for (int i = 0; i < lhs.size(); ++i)
		buff[i] = lhs._buff[i] - rhs._buff[i];
	return Vector(lhs.size(), buff);
}
Vector operator -(Vector & rhs)
{
	ElementPtr buff = new ElementType[rhs.size()];
	for (int i = 0; i < rhs.size(); ++i)
		buff[i] = -rhs._buff[i];
	return Vector(rhs.size(), buff);
}
Vector operator +( Vector &lhs, ElementType e)
{
	ElementPtr buff = new ElementType[lhs.size()];
	for (int i = 0; i < lhs.size(); ++i)
		buff[i]=lhs._buff[i]+e;
	return Vector(lhs.size(),buff);
}
Vector operator -(Vector &lhs, ElementType e)
{
	ElementPtr buff = new ElementType[lhs.size()];
	for (int i = 0; i < lhs.size(); ++i)
		buff[i] = lhs._buff[i] - e;
	return Vector(lhs.size(), buff);
}

Vector operator *(Vector &lhs, ElementType scale)
{
	ElementPtr buff = new ElementType[lhs.size()];
	for (int i = 0; i < lhs.size(); ++i)
		buff[i] =lhs._buff[i]*scale;
	return  Vector(lhs.size(), buff);
}
bool operator ==(const Vector &lhs, const Vector &rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	else
	{
		for (int i = 0; i < lhs.size(); ++i)
		{
			if (lhs._buff[i] != rhs._buff[i])
				return false;
		}
	}
	return true;
}
bool operator !=(const Vector &lhs, const Vector &rhs)
{
	return !(lhs == rhs);
}
void Vector::_clear()
{
	delete[]_buff;
	_size = 0;
	_buff = nullptr;
}
Vector::~Vector()
{
	_clear();
}