#include "libft.h"

int	ft_sizedouble(double nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 1)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_lsizedouble(long double nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 1)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}
