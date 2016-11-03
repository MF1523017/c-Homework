#pragma once
#include"Vector.h"
#include<iostream>
using VectorPtr = Vector *;
class Matrix
{
	friend Matrix operator *(const Matrix &lhs, ElementType scale);
	friend bool operator ==(const Matrix &lhs, const Matrix &rhs);
	friend bool operator !=(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator +(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator *(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator -(const Matrix &lhs, const Matrix &rhs);
	friend Matrix operator -(const Matrix &rhs);
	friend std::ostream &operator<<(std::ostream &os, const Matrix &rhs);
public:
	static Matrix INVALID_MATRIX;
	Matrix() :_rows(0), _cols(0), _vectors(nullptr) {};
	~Matrix() {
		_clear();
	}
	Matrix(int rows, int cols, ElementPtr buff) :_rows(rows), _cols(cols)
	{
		_vectors = new Vector[rows];
		for (int i = 0; i < rows; ++i)
		{
			_vectors[i] = Vector(cols, &buff[i*cols]);
		}
	}
	Matrix(int rows, VectorPtr buff) :_rows(rows),_cols(buff->size())
	{
		_vectors = new Vector[rows];
		for (int i = 0; i < rows; ++i)
		{
			_vectors[i] = buff[i];
		}
	}
	Matrix(const Vector &buff) :_rows(1), _cols(buff.size())
	{
		_vectors = new Vector;
		_vectors[0] = buff;
		
	}
	Matrix(int rows, int cols, ElementType e):_rows(rows),_cols(cols)
	{
		_vectors = new Vector[rows];
		for (int i = 0; i < rows; ++i)
		{
			_vectors[i] = Vector(cols, e);
		}
	}
	
	Matrix(const Matrix &rhs):_rows(rhs.rows()),_cols(rhs.cols())
	{
		*this = rhs;
	}
	Matrix &operator =(const Matrix &rhs);
	
	const Vector & operator [](int index) { return _vectors[index]; }
	int rows() const { return _rows; };
	int cols() const { return _cols; };
	Matrix  trans();
private:
	int _rows;
	int _cols;
	VectorPtr _vectors;
	void _clear();
};
Matrix operator *(const Matrix &lhs, ElementType scale);
Matrix operator +(const Matrix &lhs, const Matrix &rhs);
Matrix operator -(const Matrix &lhs, const Matrix &rhs);
Matrix operator *(const Matrix &lhs, const Matrix &rhs);
Matrix operator -(const Matrix &rhs);
bool operator ==(const Matrix &lhs, const Matrix &rhs);
bool operator !=(const Matrix &lhs, const Matrix &rhs);
std::ostream &operator<<(std::ostream &os, const Matrix &rhs);