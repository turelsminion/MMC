#include "../include/matrix.h"

double	**trans(double **A1, double**A2, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			A1[i][j] = A2[i][j];
	}
	return (A1);
}

double	*trans_b(double *b1, double *b2, int n)
{
	int i;

	i = -1;
	while (++i < n)
		b1[i] = b2[i];
	return (b1);
}

void	Matrix::elem_Gauss()
{
	int		i;
	int		j;
	int		k;
	double	aux;
	double	***A1;
	double	**b1;

	A1 = new double**[n];
	i = -1;
	while (++i < n)
		A1[i] = new double*[n];
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			A1[i][j] = new double[n];
	}
	b1 = new double*[n];
	i = -1;
	while (++i < n)
		b1[i] = new double[n];
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			A1[0][i][j] = A[i][j];
	}
	i = -1;
	while (++i < n)
	{
		b1[0][i] = b[i];
	}
	k = -1;
	while (++k < n - 1)
	{
		i = -1;
		while (++i < n)
		{
			j = -1;
			while (++j < n)
			{
				if (i <= k)
					A1[k + 1][i][j] = A1[k][i][j];
				else if (i > k && j <= k)
					A1[k + 1][i][j] = 0;
				else if (i > k && j > k)
					A1[k + 1][i][j] = A1[k][i][j] - (A1[k][i][k] * A1[k][k][j] / A1[k][k][k]);
			}
		}
		i = -1;
		while (++i < n)
		{
			if (i <= k)
				b1[k + 1][i] = b1[k][i];
			else if (i > k)
				b1[k + 1][i] = b1[k][i] - (A1[k][i][k] * b1[k][k] / A1[k][k][k]);
		}
	}
	x[n - 1] = b1[n - 1][n - 1] / A1[n - 1][n - 1][n - 1];
	i = n - 1;
	aux = 0;
	while (--i >= 0)
	{
		j = i;
		while (++j < n)
			aux += A1[i][i][j] * x[j];
		x[i] = (b1[i][i] - aux) / A1[i][i][i];
		aux = 0;
	}
	i = -1;
	while (++i < n)
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
}
