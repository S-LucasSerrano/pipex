#include "libft_lst.h"
#include <stdlib.h>

/* Returns the number of elements in <lst> */
int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/* Returs a pointer to the last element of <lst> */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* Returns a pointer to the previous node to <current> in <lst>.
* Returns NULL if <current> is the first element. */
t_list	*ft_lstprev(t_list *lst, t_list *current)
{
	if (!lst || !current)
		return (NULL);
	if (lst == current)
		return (NULL);
	while (lst->next)
	{
		if (lst->next == current)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
