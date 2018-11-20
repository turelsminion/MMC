#include "../include/matrix.h"

void	Matrix::Cholescky()
{
	double	**L;
	double	**LT;
	double	*y;
	double	aux;
	int		i;
	int		j;
	int		k;

	y = new double[n];
	L = new double*[n];
	i = -1;
	while (++i < n)
		L[i] = new double[n];
	LT = new double*[n];
	i = -1;
	while (++i < n)
		LT[i] = new double[n];
	L[0][0] = sqrt(A[0][0]);
	i = 0;
	while (++i < n)
	{
		L[i][0] = A[i][0] / L[0][0];
	}
	aux = 0;
	k = 0;
	while (++k < n)
	{
		j = -1;
		while (++j <= k - 1)
			aux = aux + pow(L[k][j], 2);
		L[k][k] = sqrt(A[k][k] - aux);
		aux = 0; 
	}
	aux = 0;
	i = 0;
	while (++i < n)
	{
		j = -1;
		while(++j < n)
		{
			if (i > j && j != 0)
			{
				k = -1;
				while (++k <= j - 1)
					aux = aux + (L[i][k] * L[j][k]);
				L[i][j] = (1 / L[j][j]) * (A[i][j] - aux);
				aux = 0;
			}
			else if (i != j && j != 0)
			{
				L[i][j] = 0;
			}
		}
	}
	aux = 0;
	y[0] = b[0] / L[0][0];
	i = 0;
	while (++i < n)
	{
		k = -1;
		while (++k <= i - 1)
			aux = aux + (L[i][k] * y[k]);
		y[i] = 1 / L[i][i] * (b[i] - aux);
	}
	aux = 0;
	x[n - 1] = y[n - 1] / L[n - 1][n - 1];
	i = n - 1;
	while (--i > -1)
	{
		k = i;
		while (++k <= n - 1)
		{
			aux = aux + (L[k][i] * x[k]);
		}
		x[i] = 1 / L[i][i] * (y[i] - aux);
		aux = 0;
	}
	i = -1;
	while (++i < n)
		cout << "x" << i + 1 << " = " << x[i] << endl;
}
