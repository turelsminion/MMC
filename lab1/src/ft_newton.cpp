#include "../include/mmc.h"

void	Function::ft_newton1(void)
{
	float c;
	float aux1;
	float aux2;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	if ((pow(b, 3) - 12 * b + 9) * (6 * b) < 0)
	{
		cout << "Functia nu converge. Metoda nu e buna" << endl;
		return ;
	}
	aux1 = b - (pow(b, 3) - 12 * b + 9) / (3 * pow(b, 2) - 12);
	aux2 = aux1 - (pow(aux1, 3) - 12 * aux1 + 9) / (3 * pow(aux1, 2) - 12);
	while(fabs(aux1 - aux2) >= eps2)
	{
		aux1 = aux2 - (pow(aux2, 3) - 12 * aux2 + 9) / (3 * pow(aux2, 2) - 12);
		aux2 = aux1 - (pow(aux1, 3) - 12 * aux1 + 9) / (3 * pow(aux1, 2) - 12);
	}
	cout << "Radacina se afla in intervalul: [" << aux1 << " , " << aux2 << "] cu aproximatia de: " << eps2 << endl;
}

void	Function::ft_newton2(void)
{
	float c;
	float aux1;
	float aux2;

	if (a > b)
	{
		c = a;
		a = b;
		b = c;
	}
	if ((2 * pow(a - 1, 2) - exp(a)) * (4 - exp(a)) < 0)
	{
		cout << "Functia nu converge. Metoda nu e buna" << endl;
		return ;
	}
	aux1 = a - (2 * pow(a - 1, 2) - exp(a)) / (4 * a - 4 - exp(a));
	aux2 = aux1 - (2 * pow(aux1 - 1, 2) - exp(aux1)) / (4 * aux1 - 4 - exp(aux1));
	while(fabs(aux1 - aux2) >= eps2)
	{
		aux1 = aux2 - (2 * pow(aux2 - 1, 2) - exp(aux2)) / (4 * aux2 - 4 - exp(aux2));
		aux2 = aux1 - (2 * pow(aux1 - 1, 2) - exp(aux1)) / (4 * aux1 - 4 - exp(aux1));
	}
	cout << "Radacina se afla in intervalul: [" << aux1 << " , " << aux2 << "] cu aproximatia de: " << eps2 << endl;
}