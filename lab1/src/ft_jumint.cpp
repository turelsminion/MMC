#include "../include/mmc.h"


void	Function::ft_jumint1(void)
{
	float c;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	if (((pow(a, 3) - 12 * a + 9) * (pow(b, 3) - 12 * b + 9)) > 0)
		cout << "In intervalul dat nu sunt radacini" << endl;
	else
	{
		while (abs(((pow(a, 3) - 12 * a + 9) - (pow(b, 3) - 12 * b + 9))) > eps1)
		{
			c = ((a + b) / 2);
			if (((pow(a, 3) - 12 * a + 9) * (pow(c, 3) - 12 * c + 9)) < 0)
					b = c;
			else
				a = c;
		}
		cout << "Radacina se afla in intervalul: [" << a << " , " << b << "], cu aproximatia de: " << eps1 << endl;
	}
}

void	Function::ft_jumint2(void)
{
	float c;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	if ((2 * pow(a - 1, 2) - exp(a)) * (2 * pow(b - 1, 2) - exp(b)) > 0)
		cout << "In intervalul dat nu sunt radacini" << endl;
	else
	{
		while (abs((2 * pow(a - 1, 2) - exp(a)) - (2 * pow(b - 1, 2) - exp(b))) > eps1)
		{
			c = ((a + b) / 2);
			if ((2 * pow(a - 1, 2) - exp(a)) * (2 * pow(c - 1, 2) - exp(c)) < 0)
				b = c;
			else
				a = c;
		}
		cout << "Radacina se afla in intervalul: [" << a << " , " << b << "], cu aproximatia de: " << eps1 << endl;
	}
}
