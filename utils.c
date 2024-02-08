#include "push_swap.h"

int	on_error(void)
{
	write(2, "ERROR\n", 6);
	return (1);
}

t_list	*free_stk(t_list *stk, int len)
{
	t_list	*tmp;

	while (len--)
	{
		tmp = stk;
		stk = stk->next;
		free(tmp);
	}
	return (NULL);
}

int	free_numsstr(char **numsstr)
{
	int	len;

	len = 0;
	while (numsstr[len])
	{
		free(numsstr[len]);
		len++;
	}
	free(numsstr);
	return (len);
}

t_list	*new_node(int *n)
{
	t_list	*elem;

	elem = ft_calloc(sizeof (t_list), 1);
	if (!elem)
		return (NULL);
	elem->content = n;
	elem->next = elem;
	elem->prev = elem;
	return (elem);

}

t_list	*get_stk(int *nums, int len)
{
	t_list	*stk;
	t_list	*tmp;

	stk = NULL;
	while (len--)
	{
		tmp = ft_lstnew(nums + len - 1);
		if (!tmp)
			return (free_stk(stk, len)); //TODO CLEAN
		if (stk)
		{
			tmp->next = stk;
			tmp->prev = stk->prev;
			stk->prev = tmp;
		}
		stk = tmp;
	}
	return (stk);
}
