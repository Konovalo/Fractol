#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*newstr;
	int		i;

	if (s && f)
	{
		i = 0;
		newstr = (char*)malloc(sizeof(char const) * (ft_strlen(s) + 1));
		if (newstr == 0)
			return (0);
		while (s[i])
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (0);
}
