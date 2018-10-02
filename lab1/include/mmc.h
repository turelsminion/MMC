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
