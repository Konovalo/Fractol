#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st;
	unsigned char	*st2;
	size_t			i;

	i = 0;
	st = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while (i < n)
	{
		if (st[i] != st2[i])
			return (st[i] - st2[i]);
		i++;
	}
	return (0);
}
