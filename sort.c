/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/13 01:19:44 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list	*stk)
{
	t_list	*tmp;

	tmp = stk->next;
	while (stk != tmp)
	{
		if (tmp->prev->num > tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sort(t_list	*stk_a)
{
	t_list		*stk_b;
	t_limits	limits;

	stk_b = NULL;
	if (is_sorted(stk_a))
		return (0);
	push_b(&stk_b, &stk_a);
	push_b(&stk_b, &stk_a);
	if (stk_b->num > stk_b->next->num)
	{
		limits.max = stk_b->num;
		limits.min = stk_b->next->num;
	}
	else
	{
		limits.max = stk_b->next->num;
		limits.min = stk_b->num;
	}
	algorithm(&stk_a, &stk_b, limits);
	return (0);
}
