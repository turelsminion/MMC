#include "../include/mmc.h"

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

	// Metoda injumatatirii
	// float a;
	// float b;
	// cout << "Dati intervalele a si b" << endl;
	// cin >> a >> b;
	
	// Function f1(a, b);
	// Function f2(a, b);

	//f1.ft_jumint1();
	//f2.ft_jumint2();


	// Metoda aproximatiei succesive
	// float x0;
	// float x1;
	// float x2;
	// cout << "Dati x0, x1 si x2 pentru a verifica convergenta" << endl;
	// cin >> x0 >> x1 >> x2;
	// Function fi1(x0, x1, x2);
	// Function fi2(x0, x1, x2);

	//fi1.ft_aprsuc1();
	//fi2.ft_aprsuc2();


	//Metoda lui Newton
	// float a;
	// float b;
	// cout << "Dati intervalul pentru a verifica convergenta" << endl;
	// cin >> a >> b;
	// Function n1(a ,b);
	// Function n2(a ,b);

	// n1.ft_newton1();
	// n2.ft_newton2();

	//Metoda secantelor
	// float a;
	// float b;
	// cout << "Dati intervalul pentru a verifica convergenta: " << endl;
	// cin >> a >> b;
	// Function n1(a ,b);
	// Function n2(a ,b);
	// n1.ft_secant1();
	// n2.ft_secant2();
}
