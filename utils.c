#include "push_swap.h"

int	on_error(void)
{
	write(2, "ERROR\n", 6);
	return (1);
}

t_list	*free_stk(t_list *stk, int len)
{
	t_list	*tmp;

	while (len >= 0)
	{
		tmp = stk;
		stk = stk->next;
		tmp->content = NULL;
		free(tmp);
		len--;
	}
	return (NULL);
}

t_list	*get_stk(int *nums, int len)
{
	t_list	*stk;
	t_list	*tmp;

	while (len >= 0)
	{
		tmp = ft_lstnew(nums + len);
		if (!tmp)
			return (free_stk(stk, len));
		tmp->next = stk;
		tmp->prev = stk->prev;
		stk->next = tmp;
		stk = tmp;
		len--;
	}
	return (stk);
}
