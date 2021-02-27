#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*t2;

	t2 = (unsigned char*)src;
	t = (unsigned char*)dest;
	i = 0;
	while (t2 != t && i < n)
	{
		t[i] = t2[i];
		i++;
	}
	return (dest);
}
