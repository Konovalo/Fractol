#include "libft.h"

int	ft_putchar_check(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (0);
}
