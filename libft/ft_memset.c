#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*t;

	t = (unsigned char*)destination;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		t[i] = cc;
		i++;
	}
	return (t);
}
