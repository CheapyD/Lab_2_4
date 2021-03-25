#pragma once
#pragma pack(1)
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Matrix
{
private:
	class Row;
	int N;
	Row* R;

	class Row
	{
	public:
		int* v;

		Row();
		Row(int N);
		int& operator[] (int j) { return v[j]; }
		const int& operator[] (const int j) const { return v[j]; }
	};

public:

	Matrix();
	Matrix(int N);
	Matrix(int N, Row* A);
	Matrix(const Matrix& A);
	~Matrix();

	int GetN() const { return N; }
	Row& operator[] (int i) { return R[i]; }
	const Row& operator [] (const int i) const { return R[i]; }

	Matrix& operator = (const Matrix& A);
	operator string() const;

	friend Matrix operator - (const Matrix& A, const Matrix& B);

	friend bool operator ==(const Matrix& A, const Matrix& B);
	friend bool operator !=(const Matrix& A, const Matrix& B);
	friend bool operator >(const Matrix& A, const Matrix& B);
	friend bool operator <(const Matrix& A, const Matrix& B);
	friend bool operator >=(const Matrix& A, const Matrix& B);
	friend bool operator <=(const Matrix& A, const Matrix& B);

	friend ostream& operator << (ostream& out, const Matrix& A);
	friend istream& operator >> (istream& in, Matrix& A);

	double MatrixNorm() const;
};