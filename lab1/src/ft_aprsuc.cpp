#include "../include/mmc.h"

void	Function::ft_aprsuc1(void)
{
	float aux;
	float aux1;

	if ((pow(x0, 2) / 4) <= 1 && (pow(x0, 2) / 4) >= 0)
		aux = x0;
	else if ((pow(x1, 2) / 4) <= 1 && (pow(x1, 2) / 4) >= 0)
		aux = x1;
	else if ((pow(x2, 2) / 4) <= 1 && (pow(x2, 2) / 4) >= 0)
		aux = x2;
	else
	{
		cout << "Functia nu converge in punctele date" << endl;
		return ;
	}
	aux1 = (pow(aux, 3) + 9) / 12;
	while(fabs(aux - aux1) >= eps2)
	{
		aux = aux1;
		aux1 = (pow(aux, 3) + 9) / 12;
	}
	cout << "Radacina se afla in intervalul: [" << aux << " , " << aux1 << "] cu aproximatia de: " << eps2 << endl;
}

void	Function::ft_aprsuc2(void)
{
	float aux;
	float aux1;

	if ((x0 - exp(x0) / 4) <= 1 && (x0 - exp(x0) / 4) >= 0)
		aux = x0;
	else if ((x1 - exp(x1) / 4) <= 1 && (x1 - exp(x1) / 4) >= 0)
		aux = x1;
	else if ((x2 - exp(x2) / 4) <= 1 && (x2 - exp(x2) / 4) >= 0)
		aux = x2;
	else
	{
		cout << "Functia nu converge in punctele date" << endl;
		return ;
	}
	aux1 = (2 * pow(aux, 2) + 2 - exp(aux)) / 4;
	while(fabs(aux - aux1) >= eps2)
	{
		aux = aux1;
		aux1 = (2 * pow(aux, 2) + 2 - exp(aux)) / 4;
	}
	cout << "Radacina se afla in intervalul: [" << aux << " , " << aux1 << "] cu aproximatia de: " << eps2 << endl;
}
