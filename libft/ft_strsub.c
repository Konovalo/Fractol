#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	newstr = (char*)malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
