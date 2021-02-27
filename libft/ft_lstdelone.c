#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	new = *alst;
	if (alst != NULL && del)
	{
		del(new->content, new->content_size);
		free(new);
		*alst = NULL;
	}
}
