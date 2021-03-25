#include "Matrix.h"

Matrix::Row::Row()
{
	v = new int[1];
	v[0] = 0;
}

Matrix::Row::Row(int N)
{
	v = new int[N];
	for (int j = 0; j < N; j++)
		v[j] = 0;
}

Matrix::Matrix()
{
	N = 1;
	R = new Row(N);
	R[0] = Row(N);
}

Matrix::Matrix(int N)
{
	this->N = N < 1 ? 1 : N;

	R = new Row[this->N];
	for (int i = 0; i < this->N; i++)
	{
		R[i] = Row(this->N);
	}
}

Matrix::Matrix(int N, Row* A)
{
	this->N = N;
	R = A;
}

Matrix::Matrix(const Matrix& a)
{
	N = a.N;

	R = new Row[this->N];
	for (int i = 0; i < this->N; i++)
	{
		R[i] = Row(this->N);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			R[i][j] = a.R[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < N; i++)
	{
		if (R[i].v != nullptr)
			delete[] R[i].v;
	}

	if (R != nullptr)
		delete[] R;
}

Matrix& Matrix::operator = (const Matrix& a)
{
	for (int i = 0; i < N; i++)
	{
		if (R[i].v != nullptr)

			delete[] R[i].v;
	}

	if (R != nullptr)
	{
		delete[] R;
	}

	N = a.N;

	R = new Row[this->N];
	for (int i = 0; i < this->N; i++)
	{
		R[i] = Row(this->N);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			R[i][j] = a.R[i][j];
		}
	}
	return *this;
}

Matrix::operator string() const
{
	stringstream sout;
	for (int i = 0; i < GetN(); i++)
	{
		for (int k = 0; k < GetN(); k++)
		{
			sout << setw(4) << R[i][k];
		}
		sout << endl;
	}
	return sout.str();
}

Matrix operator - (const Matrix& A, const Matrix& B)
{
	Matrix tmp(A.GetN());
	for (int i = 0; i < A.GetN(); i++)
	{
		for (int k = 0; k < A.GetN(); k++)
		{

			tmp[i][k] = A[i][k] - B[i][k];
		}
	}
	return tmp;
}

bool operator ==(const Matrix& a, const Matrix& b)
{
	if (a.GetN() != b.GetN())
		return false;

	for (int i = 0; i < a.GetN(); i++)
	{
		for (int k = 0; k < a.GetN(); k++)
		{
			if (a[i][k] != b[i][k])
				return false;
		}
	}
	return true;
}

bool operator != (const Matrix& a, const Matrix& b)
{
	return !(a == b);
}

bool operator > (const Matrix& a, const Matrix& b)
{
	if (a.GetN() < b.GetN())
		return false;

	for (int i = 0; i < a.GetN(); i++)
	{
		for (int k = 0; k < a.GetN(); k++)
		{
			if (a[i][k] < b[i][k])
				return false;
		}
	}
	return true;
}

bool operator < (const Matrix& a, const Matrix& b)
{
	if (a.GetN() > b.GetN())
		return false;

	for (int i = 0; i < a.GetN(); i++)
	{
		for (int k = 0; k < a.GetN(); k++)
		{
			if (a[i][k] > b[i][k])
				return false;
		}
	}
	return true;
}

bool operator >= (const Matrix& a, const Matrix& b)
{
	return !(a < b);
}

bool operator <= (const Matrix& a, const Matrix& b)
{
	return !(a > b);
}

ostream& operator << (ostream& out, const Matrix& a)
{
	out << string(a);
	return out;
}

istream& operator >> (istream& in, Matrix& n)
{
	for (int i = 0; i < n.GetN(); i++)
	{
		for (int j = 0; j < n.GetN(); j++)
		{
			cout << "Mas[" << i << "][" << j << "] = "; in >> n[i][j];
		}
		cout << endl;
	}
	return in;
}

double Matrix::MatrixNorm() const
{
	int b = 0;
	for (int i = 0; i < this->GetN(); i++)
	{
		for (int k = 0; k < this->GetN(); k++)
		{
			b += (this->R[i][k] * this->R[i][k]);
		}
		cout << endl;
	}
	return sqrt(b);
}




