#include <iostream>
#include <cmath>
#include <time.h>
#include <unistd.h>


using namespace std;

class Poll
{
	protected:
		int		n;
		double	*x1;
		double	*y;

	public:
		void	LaGranje(double x);
		double	f(double x);
		Poll(int n)
		{
			int i;

			this->n = n;
			x1 = new double[n];
			y = new double[n];
			i = -1;
			cout << endl << "Dati X-urile: " << endl;
			while (++i < n)
			{
				cin >> x1[i];
				y[i] = f(x1[i]);
			}
		}
};