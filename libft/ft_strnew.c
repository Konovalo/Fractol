#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (s);
	ft_memset(s, 0, size + 1);
	return (s);
}
