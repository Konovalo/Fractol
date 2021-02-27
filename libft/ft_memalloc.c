#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *s;

	s = (void*)malloc(sizeof(void) * size);
	if (s == NULL)
		return (s);
	return (ft_memset(s, 0, size));
}
