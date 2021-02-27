#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (!lst || (!f) || !(new = f(lst)))
		return (NULL);
	head = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
		{
			while (head)
			{
				new = head;
				free(new);
				head = head->next;
			}
			return (NULL);
		}
		new = new->next;
	}
	return (head);
}
