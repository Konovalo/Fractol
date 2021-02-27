#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	int		i;

	if (s && f)
	{
		t = (char*)malloc(sizeof(char const) * (ft_strlen(s) + 1));
		if (t == NULL)
			return (0);
		i = 0;
		while (s[i])
		{
			t[i] = f(s[i]);
			i++;
		}
		t[i] = '\0';
		return (t);
	}
	return (0);
}
