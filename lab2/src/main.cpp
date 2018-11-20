#include "../include/matrix.h"

int main()
{
	int c;
	int n;


	cout << "Dati va rog gradul matricei:" << endl;
	cin >> n;
	Matrix m = Matrix(n);
	Afisare();
	while (1)
	{
		cout << "Alegeti optiunea: ";
		cin >> c;
		switch(c)
		{
			case 0:
			{
				Afisare();
				break;
			}
			case 1:
			{
				m.Afisare_matrix();
				break;
			}
			case 2:
			{
				m.Cholescky();
				break;
			}
			case 3:
			{
				m.Jacobi();
				break;
			}
			case 4:
			{
				m.Gaus_Seidel();
				break;
			}
			case 5:
			{
				m.elem_Gauss();
				break;
			}
			case 6:
			{
				cout << "Iesire reusita!" << endl;
				return (0);
			}
			cout << endl;
		}
	}
	return (0);
}

void	Afisare()
{
	cout << "Alegeti metoda dorita:" << endl;
	cout << "[0] Afisati optiunile;" << endl;
	cout << "[1] Afisati matricea;" << endl;
	cout << "[2] Metoda lui Cholesky;" << endl;
	cout << "[3] Metoda lui Jacobi;" << endl;
	cout << "[4] Metoda lui Gauss-Seidel;" << endl;
	cout << "[5] Metoda eleminarii Gauss;" << endl;
	cout << "[6] Exit;" << endl;
}

void	Matrix::Afisare_matrix()
{
	int i;
	int j;

	cout << "Matricea A :" << endl;
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	i = -1;
	while (++i < n)
		cout << b[i] << " ";
	cout << endl;
}
