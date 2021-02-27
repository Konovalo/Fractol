#include "libft.h"

static char		*perevorot(long long int n, char *newstr, int flag, int kol)
{
	newstr[kol] = '\0';
	kol--;
	if (n == 0)
	{
		newstr[kol] = '0';
		return (newstr);
	}
	if (flag == 1)
		n = n * (-1);
	while (n > 0)
	{
		newstr[kol] = n % 10 + '0';
		n = n / 10;
		kol--;
	}
	if (flag == 1)
		newstr[kol] = '-';
	return (newstr);
}

static int		scet(long long int new, int kol)
{
	while (new > 0)
	{
		new = new / 10;
		kol++;
	}
	return (kol);
}

char			*ft_llitoa(long long int n)
{
	char			*newstr;
	int				kol;
	long long int	new;
	int				flag;

	kol = 0;
	new = n;
	flag = 0;
	if (n == -9223372036854775807)
		return (ft_strdup("9223372036854775807"));
	if (n + 1 == -9223372036854775807)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
	{
		new *= (-1);
		kol = 1;
		flag = 1;
	}
	kol = scet(new, kol);
	if (n == 0 || n == (-0))
		kol = 1;
	newstr = (char*)malloc(sizeof(char) * (kol + 1));
	if (newstr == NULL)
		return (0);
	return (perevorot(n, newstr, flag, kol));
}
