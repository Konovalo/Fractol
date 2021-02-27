#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*t;
	int		i;
	int		n;

	t = (char*)s;
	i = 0;
	n = ft_strlen(s);
	while (i < n + 1)
	{
		if (*t != c)
			t++;
		else
			return (t);
		i++;
	}
	return (0);
}
