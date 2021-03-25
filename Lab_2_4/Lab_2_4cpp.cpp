#include "Matrix.h"

int main()
{
	int N1, N2;

	cout << "N1 = "; cin >> N1;
	Matrix A(N1);
	cin >> A;
	cout << "Matrix A:" << endl;
	cout << A << endl;

	cout << "N2 = "; cin >> N2;
	Matrix B(N2);
	cin >> B;
	cout << "Matrix B:" << endl;
	cout << B << endl;

	cout << "Matrix C(Subtract):" << endl;
	Matrix C = A - B;
	cout << C << endl;

	cout << "Norm Square = " << C.MatrixNorm() << endl;
	cout << "Size of class = " << sizeof(C) << endl;

	if (A == B)
		cout << "Matrix are equal" << endl;
	else
		cout << "Matrix are not equal" << endl;

	if (A != B)
		cout << "Matrix are not equal" << endl;
	else
		cout << "Matrix are equal" << endl;

	if (A > B)
		cout << "Matrix A is bigger than Matrix B" << endl;
	else
		cout << "Matrix A is smaller than Matrix B" << endl;

	if (A < B)
		cout << "Matrix A is smaller than Matrix B" << endl;
	else
		cout << "Matrix A is bigger than Matrix B" << endl;

	if (A >= B)
		cout << "Matrix A is bigger than/equal to Matrix B" << endl;
	else
		cout << "Matrix A is smaller than/equal to Matrix B" << endl;

	if (A <= B)
		cout << "Matrix A is smaller than/equal to Matrix B" << endl;
	else
		cout << "Matrix A is bigger than/equal to Matrix B" << endl;
}
