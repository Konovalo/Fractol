#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t n;
	size_t n2;
	size_t ii;

	ii = 0;
	n = ft_strlen(dst);
	n2 = ft_strlen(src);
	if (n >= dstsize)
		return (n2 + dstsize);
	while (src[ii] && ii < (dstsize - n - 1))
	{
		dst[n + ii] = src[ii];
		ii++;
	}
	dst[n + ii] = '\0';
	return (n + n2);
}
