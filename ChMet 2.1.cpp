// ChMet 2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cmath> 
#include <iostream>
using namespace std;

void Gauss_method(double **matrix, int m, int n);
void show_matrix(double **matrix, int x, int y);

int main()
{
	//матрица m x n
	int n = 3; //количество строк
	int m = 4; //количество столбцов
	//cout << "Please enter the number of columns and rows\nNumber of columns -> ";
	//cin >> m; //количество строк
	//cout << "Number of rows -> ";
	//cin >> n; //количество столбцов
	if (n == m - 1) {
		double **A = new double*[n];
		for (int i = 0; i < n; i++)
			A[i] = new double[m];
		/*cout << "Please enter matrix:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> A[i][j];
			}
		}*/
		A[0][0] = 2.0; A[0][1] = 3.0; A[0][2] = 4.0; A[0][3] = 5.0;
		A[1][0] = 3.0; A[1][1] = 4.0; A[1][2] = 5.0; A[1][3] = 6.0;
		A[2][0] = 4.0; A[2][1] = 5.0; A[2][2] = 6.0; A[2][3] = 7.0;
		cout << '\n';
		//show matrix
		show_matrix(A, m, n);
		Gauss_method(A, m, n);
		show_matrix(A, m, n);
		//delete matrix
		for (int i = 0; i < n; i++)
		{
			delete[] A[i];
		}
	}
	else cout << "Error! Matrix is not optimal.\n";
	system("pause");
	return 0;
}

void show_matrix(double **matrix, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Action(double **matrix, int x, int y, int start)
{
	if (matrix[start][start] != 0)
	{
		for (int i = start + 1; i < y; i++)
		{
			double* temp = new double[x - start];
			for (int j = 0; j < (x - start); j++)
			{
				temp[j] = (-(matrix[i][start]) / matrix[start][start])*matrix[start][j + start];
			}
			for (int j = 0; j < (x - start); j++)
			{
				matrix[i][j + start] = temp[j] + matrix[i][j + start];
			}
		}
	}
}

void Gauss_method(double **matrix, int x, int y)
{
	//	double * answer = new double[y];
	for (int start = 0; start < y; start++)
	{
		Action(matrix, x, y, start);
	}
	for (int j = y; j > 0; j--)
	{
		double temp;
		for (int i = 0; i < j; i++)
		{

		}
	}
}

