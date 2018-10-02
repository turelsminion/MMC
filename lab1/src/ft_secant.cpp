#include "../include/mmc.h"

void	Function::ft_secant1(void)
{
	float	x0;
	float	xpred;
	float	x1;

	x0 = a + eps2;
	x1 = b - eps2;
	if ( x0 - (((pow(x0, 3) - 12 * x0 + 9) * (x1 - x0)) / ((pow(x1, 3) - 12 * x1 + 9) - (pow(x0, 3) - 12 * x0 + 9))) < a ||
		x0 - (((pow(x0, 3) - 12 * x0 + 9) * (x1 - x0)) / ((pow(x1, 3) - 12 * x1 + 9) - (pow(x0, 3) - 12 * x0 + 9))) > b)
	{
		cout << "In intervalul dat nu este radacina" << endl;
		return ;
	}
	cout << x0 << " " << x1 << " " << fabs(a - b) << endl;
	while (fabs(x0 - x1) >= eps2)
	{
		xpred = x1;
		x1 = x0 - (((pow(x0, 3) - 12 * x0 + 9) * (x1 - x0)) / ((pow(x1, 3) - 12 * x1 + 9) - (pow(x0, 3) - 12 * x0 + 9)));
		x0 = xpred;
		cout << x0 << " " << x1 << endl;
	}
	cout << "Radacina se afla pe intervalul [" << x0 << " , " << x1 << "];" << endl;
}

void	Function::ft_secant2(void)
{
	float	x0;
	float	xpred;
	float	x1;

	x0 = a + eps2;
	x1 = b - eps2;
	if (x0 - (((2 * (pow((x1 - 1), 2) - exp(x1)) * (x1 - x0)) / ((2 * pow(x1 - 1, 2) - exp(x1)) - (2 * pow(x0 - 1, 2) - exp(x0))))) < a ||
		x0 - (((2 * (pow((x1 - 1), 2) - exp(x1)) * (x1 - x0)) / ((2 * pow(x1 - 1, 2) - exp(x1)) - (2 * pow(x0 - 1, 2) - exp(x0))))) > b)
	{
		cout << "In intervalul dat nu este radacina" << endl;
		return ;
	}
	cout << x0 << " " << x1 << " " << fabs(x0 - x1) << endl;
	while (fabs(x0 - x1) >= eps2)
	{
		xpred = x1;
		x1 = x0 - (((2 * (pow((x1 - 1), 2) - exp(x1)) * (x1 - x0)) / ((2 * pow(x1 - 1, 2) - exp(x1)) - (2 * pow(x0 - 1, 2) - exp(x0)))));
		x0 = xpred;
		cout << x0 << " " << x1 << endl;
	}
	cout << "Radacina se afla pe intervalul [" << x0 << " , " << x1 << "];" << endl;
}