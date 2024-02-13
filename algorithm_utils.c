/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:14:21 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/13 01:26:05 by molasz-a         ###   ########.fr       */
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

int	abs_move(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max_move(int n1, int n2)
{
	if (abs_move(n1) > abs_move(n2))
		return (n1);
	return (n2);
}

int	calc_move(int num, t_list *stk_b, t_limits limits)
{
	t_list	*tmp;
	int		size;
	int		len;

	size = 0;
	tmp = stk_b;
	len = stksize(stk_b);
	while (size < len)
	{
		if ((num < limits.min || num > limits.max) && tmp->num == limits.max)
			return (size);
		if (num < tmp->prev->num && num > tmp->num)
			return (size);
		size++;
		tmp = tmp->next;
	}
	if (size < (len / 2) + 1)
		return (size);
	else
		return (size - len);
}
