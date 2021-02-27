#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t dl;

	i = 0;
	dl = ft_strlen(dest);
	while (i < n && *src)
	{
		dest[dl] = *src;
		src++;
		dl++;
		i++;
	}
	dest[dl] = '\0';
	return (dest);
}
