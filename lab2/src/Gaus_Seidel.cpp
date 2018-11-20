#include "../include/matrix.h"

void	Matrix::Gaus_Seidel()
{
	double	**Q;
	int		i;
	int		j;
	int		k;
	double	aux;
	double	*X1;
	double	*d;
	double	t;
	int		a;

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
	cout << "Aici se afla Q:" << endl;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (i == j)
				Q[i][j] = 0;
			else
				Q[i][j] = (A[i][j] / A[i][i]) * -1;
			cout << "Q[" << i + 1 << "][" << j + 1 << "] = " << Q[i][j] << " ";
		}
		cout << endl;
	}
	d = new double[n];
	i = -1;
	cout << endl <<"Aici se afla d:" << endl;
	while (++i < n)
	{
		d[i] = b[i] / A[i][i];
		cout << "d[" << i + 1 << "] = " << d[i] << " ";
	}
	cout << endl;
	X1 = new double[n];
	i = -1;
	cout << endl << "Aici initializam x:" << endl;
	while (++i < n)
	{
		x[i] = b[i];
		cout << "x[" << i + 1 << "] = " << x[i] << " ";
	}
	cout << endl;
	i = -1;
	cout << endl << "Aici se afla x-ul dupa prima iteratie:" << endl;
	while (++i < n)
	{
		j = -1;
		while (++j <= i - 1)
			aux = aux + (Q[i][j] * X1[j]);
		j = i - 1;
		while (++j < n)
			aux = aux + (Q[i][j] * x[j]);
		X1[i] = aux + d[i];
		cout << "x[" << i + 1 << "] = " << X1[i] << " ";
		aux = 0;
	}
	cout << endl;
	cout << endl << "Aici se afla x-ul dupa toate iteratiile:" << endl;
	a = 1;
	aux = 0;
	while (verificare(x, X1))
	{
		i = -1;
		while (++i < n)
		{
			t = X1[i];
			j = -1;
			while (++j <= i - 1)
				aux = aux + (Q[i][j] * X1[j]);
			while (++j < n)
				aux = aux + (Q[i][j] * X1[j]);
			X1[i] = aux + d[i];
			x[i] = t;
			aux = 0;
		}
		i = -1;
		a++;
		cout << endl << "X-ul la iteratia " << a << "-a este:" << endl;
		while (++i < n)
			cout << "X" << a << "[" << i + 1 << "] = " << X1[i] << endl;
		cout << endl;
	}
	i = -1;
	while (++i < n)
		cout << "x" << i + 1 << " = " << X1[i] << endl;
}
