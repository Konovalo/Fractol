#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
