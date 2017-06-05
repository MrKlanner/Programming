// ChMet 2.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double* Progonki_method(int n, double *a, double *b, double *c, double *d/*, double *Q, double *P, double *res*/);
void check(double **matrix, double *d, double *roots, int n);

int main()
{
	int n = 5;
	double *ans = new double[n];
	double *a = new double[n]; double *b = new double[n];
	double *c = new double[n]; double *d = new double[n];
	//double *Q = new double[n]; double *P = new double[n]; double *res = new double[n];
	a[0] = 0; a[1] = 0; a[2] = 6; a[3] = 4; a[4] = -7;
	b[0] = -11; b[1] = -8; b[2] = 15; b[3] = 6; b[4] = -10;
	c[0] = 9; c[1] = 3; c[2] = -2; c[3] = -6; c[4] = -1;
	d[0] = -158; d[1] = 66; d[2] = -45; d[3] = 24; d[4] = -1;
	//Q[0] = d[0] / b[0];
	ans = Progonki_method(n, a, b, c, d);
	delete[] b;
	delete[] c;
	delete[] d;
	cout << '\n';

	for (int i = 0; i < n; i++)
	{
		cout << 'x' << i+1 << '=' << ans[i] << endl;
	}
	check(matrix, d, ans, n);
	delete[] a;
	system("pause");
    return 0;
}

double* Progonki_method(int n, double* a, double* b, double* c, double* d/*, double* Q, double* P, double* res*/)
{
	double *P = new double[n];
	double *Q = new double[n];
	double *res = new double[n];
	P[0] = -(c[0] / b[0]);
	Q[0] = d[0] / b[0];
	P[n - 1] = 0;
	for (int i = 1; i < n-1; i++)
	{
		P[i] = -c[i] / (b[i] + (a[i] * P[i - 1]));
		Q[i] = (d[i] - (a[i] * Q[i - 1])) / (b[i] + (a[i] * P[i - 1]));
	}
	Q[n - 1] = (d[n - 1] - (a[n - 1] * Q[n - 2])) / (b[n - 1] + (a[n - 1] * P[n - 2]));
	for (int i = n-1; i >= 0; i--)
	{
		res[i] = P[i] * res[i+1] + Q[i];
	}
	for (int i = 0; i < n; i++)
		cout << "P" << i + 1 << '=' << P[i] << endl;
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << "Q" << i + 1 << '=' << Q[i] << endl;
	delete[] P;
	delete[] Q;
	return res;
}

void check(double **matrix, double *d, double *roots, int n)
{
	cout << endl << endl;
	cout << "Check" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = matrix[i][j] * roots[j];
			cout << temp << '+' << ' ';
		}
		cout << '=' << ' ' << d[i] << endl;
	}
}