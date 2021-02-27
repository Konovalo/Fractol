#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	if (ft_strlen(src) < n)
	{
		while (i < ft_strlen(src))
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
		return (dest);
	}
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
