#include "libft.h"

int	ft_putstr_check(char const *s)
{
	if (s != NULL)
		if (write(1, s, ft_strlen(s)) < 0)
			return (-1);
	return (0);
}
