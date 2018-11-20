#include <iostream>
#include <cmath>
#include <time.h>
#include <unistd.h>

using namespace std;

#define eps		pow(10, -6)

class	Matrix
{
	protected:
		int		n;
		double	**A;
		double	*b;
		double	*x;

	public:
		int		verificare(double *X1, double *X2);
		void	elem_Gauss();
		void	Cholescky();
		void	Afisare_matrix();
		void	Jacobi();
		void	Gaus_Seidel();
		Matrix(int n)
		{
			int	i;
			int j;

			this->n = n;
			A = new double*[n];
			i = -1;
			while (++i < n)
				A[i] = new double[n];
			b = new double[n];
			i = -1;
			cout << "Dati elementele matricei A:" << endl;
			while (++i < n)
			{
				j = -1;
				while (++j < n)
				{
					cin >> A[i][j];
				}
			}
			i = -1;
			cout << "Dati elementele vectorului b:" << endl;
			while (++i < n)
			{
				cin >> b[i];
			}
			x = new double[n];
		}
};

void	Afisare();
