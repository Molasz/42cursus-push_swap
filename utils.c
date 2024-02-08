/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:18:02 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/08 16:42:57 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;

	stk = NULL;
	i = 0;
	while (len > i)
	{
		tmp = new_node(nums + len - i - 1);
		if (!tmp)
			return (free_stk(stk, i));
		if (stk)
		{
			tmp->next = stk;
			tmp->prev = stk->prev;
			stk->prev = tmp;
		}
		stk = tmp;
		i++;
	}
	while (1 != len--)
		tmp = tmp->next;
	tmp->next = stk;
	return (stk);
}
