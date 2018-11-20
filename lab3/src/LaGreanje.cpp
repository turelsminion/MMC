#include "../include/pol.h"

void	Poll::LaGranje(double x)
{
	double	sum;
	double	prod;
	int		i;
	int		j;

	sum = 0;
	i = -1;
	while (++i < n)
	{
		j = -1;
		prod = 1;
		while (++j < n)
			if (j != i)
				prod *= (x - x1[j]) / (x1[i] - x1[j]);
		sum += y[i] * prod;
	}
	cout << "Rezultatul este : " << sum << endl;
}
