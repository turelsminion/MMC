#include "../include/matrix.h"

void	Matrix::Jacobi()
{
	double	*X1;
	double	**Q;
	int		i;
	int		j;
	double	t;
	double	aux;
	double	*d;
	int		k;

	i = -1;
	while (++i < n)
		if (A[i][i] == 0)
		{
			cout << "Metoda nu converge situatiei";
			return ;
		}
	Q = new double*[n];
	i = -1;
	while (++i < n)
		Q[i] = new double[n];
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (i == j)
				Q[i][j] = 0;
			else
				Q[i][j] = (A[i][j] / A[i][i]) * -1;
		}
	}
	cout << endl << "Aici se afla Q:" << endl;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			cout << "Q[" << i + 1 << "][" << j + 1 << "] = " << Q[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	X1 = new double[n];
	i = -1;
	cout << endl << "Aici este x initial:" << endl;
	while (++i < n)
	{
		x[i] = b[i];
		cout << "x[" << i + 1 << "] = " << x[i] << " ";
	}
	cout << endl;
	d = new double[n];
	i = -1;
	cout << endl << "Aici se afla d:" << endl;
	while (++i < n)
	{
		d[i] = b[i] / A[i][i];
		cout << "d[" << i + 1 << "] = " << d[i] << " ";
	}
	cout << endl;
	i = -1;
	aux = 0;
	cout << endl << "Aici este reprezentat x dupa prima iteratie:" << endl;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			aux = aux + Q[i][j] * x[j];
		X1[i] = aux + d[i];
		cout << "X1[" << i + 1 << "]" << " ";
	}
	cout << endl;
	aux = 0;
	cout << endl << "Toate iteratiile pentru aflarea x-ului:" << endl;
	k = 1;
	while (verificare(X1, x))
	{
		i = -1;
		while (++i < n)
		{
			t = X1[i];
			j = -1;
			while (++j < n)
				aux = aux + Q[i][j] * X1[j];
			X1[i] = aux + d[i];
			x[i] = t;
			aux = 0;
		}
		k++;
		cout << endl << "X-ul dupa " << k << "-a iteratie:" << endl;
		i = -1;
		while (++i <  n)
			cout << "X" << i << " = [" << X1[i] << "]" << " ";
		cout << endl;
	}
	cout << endl;
	i = -1;
	while (++i < n)
		cout << "x" << i + 1 << " = " << X1[i] << endl;
}

int		Matrix::verificare(double *X1, double *X2)
{
	int i;

	i = -1;
	while (++i < n)
		if (abs(X1[i] - X2[i]) > eps)
			return (1);
	return (0);
}
