#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		start;

	start = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[start] && start < len)
	{
		i = 0;
		while (needle[i] && haystack[start + i] && \
				haystack[start + i] == needle[i] && (start + i) < len)
			i++;
		if (i == ft_strlen(needle))
			return ((char *)(haystack + start));
		start = start + 1;
	}
	return (NULL);
}
