#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (*ss1 && *ss2 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
	}
	if (*ss1 == '\0' && *ss2 == '\0')
		return (0);
	return (*ss1 - *ss2);
}
