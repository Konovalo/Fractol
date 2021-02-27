#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*t;
	size_t			i;

	cc = (unsigned char)c;
	t = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (*t == cc)
			return (t);
		t++;
		i++;
	}
	return (0);
}
