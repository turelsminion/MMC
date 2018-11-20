#include "../include/pol.h"

int main()
{
	int	n;
	double x;

	cout << "Dati citi de x doriti sa introduceti: ";
	cin >> n;
	Poll m = Poll(n);
	cout << "Dati x pentru aflearea rezultatului: ";
	cin >> x;
	m.LaGranje(x);
	return (0);
}
