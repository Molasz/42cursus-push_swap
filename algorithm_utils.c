/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:14:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/15 18:37:50 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stksize(t_list *stk)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!stk)
		return (0);
	tmp = stk->prev;
	while (stk != tmp)
	{
		i++;
		stk = stk->next;
	}
	return (i + 1);
}

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

int	max_move(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}
