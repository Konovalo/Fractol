#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	int		i;

	if (s == NULL)
		return (NULL);
	t = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (t == NULL)
		return (t);
	i = 0;
	while (*s)
	{
		t[i] = *s;
		i++;
		s++;
	}
	t[i] = '\0';
	return (t);
}
