#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*t;
	int		kol;
	int		i;

	kol = ft_strlen(needle);
	if (*needle == '\0')
		return ((char*)haystack);
	while (*needle && *haystack)
	{
		t = ft_strchr(haystack, needle[0]);
		if (t == 0)
			return (0);
		else
		{
			i = 1;
			while (needle[i] != '\0' && (t[i] == needle[i]))
				i++;
			if (needle[i] == '\0')
				return (t);
		}
		haystack = t + 1;
	}
	return (NULL);
}
