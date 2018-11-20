#include <iostream>
#include <cmath>
#include <time.h>
#include <unistd.h>

using namespace std;

class Function
{
	protected:
		float x;
		float a;
		float b;
		float x0;
		float x1;
		float x2;
		float eps1 = pow(10, -2);
		float eps2 = pow(10, -6);
	
	public:
		void	ft_jumint1(void);
		void	ft_jumint2(void);
		void	ft_aprsuc1(void);
		void	ft_aprsuc2(void);
		void	ft_newton1(void);
		void	ft_newton2(void);
		void	ft_secant1(void);
		void	ft_secant2(void);
		Function(float a, float b)
		{
			this->a = a;
			this->b = b;
		}
		Function(float x0, float x1, float x2)
		{
			this->x0 = x0;
			this->x1 = x1;
			this->x2 = x2;
		}
};

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

int	main()
{
	int	m;
	int k;
	int l;
	float a;
	float b;
	float x0;
	float x1;
	float x2;

in:	while (1)
	{	
		system("clear");
		cout << "Meniu" << endl;
		cout << "1. x^3 - 12*x + 9 = 0" << endl;
		cout << "2. 2 * (x - 1) ^ 2 - e ^ x = 0" << endl;
		cout << "Dati comanda: ";
		cin >> m; 
		system("clear");
		switch (m)
		{
			case 1:
			{	
				system("clear");
				cout << "Meniu:" << endl;
				cout << "1. Metoda injumatatirii intervalelor" << endl;
				cout << "2. Metoda aproximatiilor succesive" << endl;
				cout << "3. Metoda lui Newton" << endl;
				cout << "4. Metoda secantelor" << endl;
				cout << "5. Inapoi" << endl;
				cout << "Dati comanda: ";
				cin >> k;
				switch (k)
				{
					case 1:
					{	
						system("clear");
						cout << "Dati intervalele a si b" << endl;
						cin >> a >> b;
						Function f1(a, b);
						f1.ft_jumint1();
						sleep(2);
						break;
					}
					case 2:
					{
						system("clear");
						cout << "Dati x0, x1 si x2 pentru a verifica convergenta" << endl;
						cin >> x0 >> x1 >> x2;
						Function fi1(x0, x1, x2);
						fi1.ft_aprsuc1();
						sleep(2);
						break;
					}
					case 3:
					{
						system("clear");
						cout << "Dati intervalul a si b pentru a verifica convergenta" << endl;
						cin >> a >> b;
						Function n1(a ,b);
						n1.ft_newton1();
						sleep(2);
						break;
					}
					case 4:
					{
						system("clear");
						cout << "Dati intervalul a si b pentru a verifica convergenta: " << endl;
						cin >> a >> b;
						Function n1(a ,b);
						n1.ft_secant1();
						sleep(2);
						break;
					}
					case 5:
					{
						goto in;
					}
				}
			}
			case 2:
			{
				system("clear");
				cout << "Meniu:" << endl;
				cout << "1. Metoda injumatatirii intervalelor" << endl;
				cout << "2. Metoda aproximatiilor succesive" << endl;
				cout << "3. Metoda lui Newton" << endl;
				cout << "4. Metoda secantelor" << endl;
				cout << "5. Inapoi" << endl;
				cout << "Dati comanda: ";
				cin >> l;
				switch (l)
				{
					case 1:
					{	
						system("clear");
						cout << "Dati intervalele a si b" << endl;
						cin >> a >> b;
						Function f2(a, b);
						f2.ft_jumint2();
						sleep(2);
						break;
					}
					case 2:
					{
						system("clear");
						cout << "Dati x0, x1 si x2 pentru a verifica convergenta" << endl;
						cin >> x0 >> x1 >> x2;
						Function fi2(x0, x1, x2);
						fi2.ft_aprsuc2();
						sleep(2);
						break;
					}
					case 3:
					{
						system("clear");
						cout << "Dati intervalul a si b pentru a verifica convergenta" << endl;
						cin >> a >> b;
						Function n2(a ,b);
						n2.ft_newton2();
						sleep(2);
						break;
					}
					case 4:
					{
						system("clear");
						cout << "Dati intervalul a si b pentru a verifica convergenta: " << endl;
						cin >> a >> b;
						Function n2(a ,b);
						n2.ft_secant2();
						sleep(2);
						break;
					}
					case 5:
					{
						goto in;
					}
				}
			}
		}
	}
	return (0);
}
