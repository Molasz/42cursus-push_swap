/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/09 18:31:41 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stksize(t_list *stk)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stk->prev;
	while (stk != tmp)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

void	put_n(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;
	int		count;
	int		len;
	int		i;

	i = 0;
	count = 0;
	len = stksize(*stk_b);
	tmp = *stk_b;
	while (*(int *)(*stk_a)->content < *(int *)tmp->content)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > len / 2)
	{
		while (i++ < count)
			rotate_b(stk_b);
		push_b(stk_b, stk_a);
		while (count-- > 0)
			reverse_b(stk_b);
	}
	else
	{
		while (i++ < count)
			reverse_b(stk_b);
		push_b(stk_b, stk_a);
		while (count-- > 0)
			rotate_b(stk_b);
	}
}

int	sort(t_list	*stk_a)
{
	t_list	*stk_b;
	int		max;
	int		min;
	int		count;

	stk_b = NULL;
	min = INT_MAX;
	max = INT_MIN;
	count = 0;
	while (stk_a)
	{

		if(max <= *(int *)stk_a->content)
		{
			max = *(int *)stk_a->content;
			push_b(&stk_b, &stk_a);
		}
		else if(min >= *(int *)stk_a->content)
		{
			min = *(int *)stk_a->content;
			push_b(&stk_b, &stk_a);
			rotate_b(&stk_b);
		}
		else
			put_n(&stk_a, &stk_b);
	}
	while (stk_b)
		push_a(&stk_a, &stk_b);
	print_stks(stk_a, stk_b);
	return (0);
}
