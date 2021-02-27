#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;
	char	*t;

	i = ft_strlen(s) + 1;
	cc = (char)c;
	t = (char*)s;
	t = t + i - 1;
	while (i > -1 && *t != cc)
	{
		t--;
		i--;
	}
	if (i != (-1))
		return (t);
	return (0);
}
