#include "libft.h"

int	ft_putstr_n_check(char const *s, int cnt)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (i < cnt)
		{
			if (ft_putchar_check(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
