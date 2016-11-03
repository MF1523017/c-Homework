#include"Matrix.h"
#include<iostream>
Matrix Matrix::INVALID_MATRIX = Matrix();
std::ostream &operator<<(std::ostream &os, const Matrix &rhs)
{
	for (int i = 0; i < rhs.rows(); ++i)
		os << rhs._vectors[i] << " ";
	return os;
}

Matrix operator *(const Matrix &lhs, ElementType scale)
{

	VectorPtr vectors = new Vector[lhs.rows()];
	for (int i = 0; i < lhs.rows(); ++i)
	{
		vectors[i] = lhs._vectors[i] * scale;
	}
	return Matrix(lhs.rows(), vectors);
}
Matrix operator *(const Matrix &lhs, const Matrix &rhs)
{
	if (lhs.cols() != rhs.rows())
		return Matrix::INVALID_MATRIX;
	ElementPtr buff = new ElementType[lhs._rows*rhs._cols];
	for (int i = 0; i < lhs.rows(); ++i)
	{
		for (int j = 0; j < rhs.cols(); ++j)
		{
			buff[i*rhs.cols() + j] = 0;
			for (int k = 0; k < rhs.rows(); ++k)
			{
				buff[i*rhs.cols() + j] += lhs._vectors[i][k] * rhs._vectors[k][j];
			}
		}
	}
	return Matrix(lhs.rows(),rhs.cols(),buff);
}
bool operator ==(const Matrix &lhs, const Matrix &rhs)
{
	if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
		return false;
	for (int i = 0; i < lhs.rows(); ++i)
	{
		if (lhs._vectors[i] != rhs._vectors[i])
			return false;
	}
	return true;
}
bool operator !=(const Matrix &lhs, const Matrix &rhs)
{
	return !(lhs == rhs);
}
Matrix operator +(const Matrix &lhs, const Matrix &rhs)
{
	VectorPtr vectors = new Vector[lhs.rows()];
	for (int i = 0; i < lhs.rows(); ++i)
	{
		vectors[i] = lhs._vectors[i] + rhs._vectors[i];
	}
	return Matrix(lhs.rows(), vectors);
}
Matrix operator-(const Matrix &lhs, const Matrix &rhs)
{
	VectorPtr vectors = new Vector[lhs.rows()];
	for (int i = 0; i < lhs.rows(); ++i)
	{
		vectors[i] = lhs._vectors[i] - rhs._vectors[i];
	}
	return Matrix(lhs.rows(), vectors);
}
Matrix operator -(const Matrix &rhs)
{
	VectorPtr vectors = new Vector[rhs.rows()];
	for (int i = 0; i < rhs.rows(); ++i)
	{
		vectors[i] = -rhs._vectors[i];
	}
	return Matrix(rhs.rows(), vectors);
}
Matrix Matrix::trans()
{
	ElementPtr buff = new ElementType[rows()*cols()];
	for (int i = 0; i < cols(); ++i)
	{
		for (int j = 0; j < rows(); ++j)
			buff[i*rows() + j] = _vectors[j][i];
	}
	return Matrix(cols(), rows(), buff);
}
Matrix &Matrix::operator =(const Matrix &rhs)
{
	if (this == &rhs)return *this;
	_clear();
	_rows = rhs.rows();
	_cols = rhs.cols();
	_vectors = new Vector[rhs.rows()];
	for (int i = 0; i < rows(); ++i)
	{	
		_vectors[i] = rhs._vectors[i];
	}
	return *this;
}
void Matrix::_clear()
{
	for (int i = 0; i < rows(); ++i)
	{
		delete[]_vectors[i]._buff;
	}
	_vectors =nullptr;
	_rows = 0;
	_cols = 0;
}
