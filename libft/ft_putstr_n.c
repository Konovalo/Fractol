#include "libft.h"

void	ft_putstr_n(char const *s, int cnt)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (i < cnt)
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}
