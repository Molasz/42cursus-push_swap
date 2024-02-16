/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/16 00:33:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_low(t_list **stk_a)
{
	t_list	*tmp;
	int		moves;
	int		pos;
	int		len;
	int		i;

	len = stksize(*stk_a);
	i = 0;
	moves = (*stk_a)->moves;
	pos = 0;
	tmp = *stk_a;
	while (i < len)
	{
		if (tmp->moves < moves)
		{
			moves = tmp->moves;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

static void	algorithm(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	int	apos;
	int	len;

	while (stksize(*stk_a) > 3)
	{
		calc_movements(*stk_a, *stk_b, limits);
		apos = find_low(stk_a);
		push_num(apos, stk_a, stk_b);
		if (limits->max < (*stk_b)->num)
			limits->max = (*stk_b)->num;
		if (limits->min > (*stk_b)->num)
			limits->min = (*stk_b)->num;
	}
	len = stksize(*stk_b);
	apos = check_position(*stk_b, limits->max, limits);
	if (apos <= (len / 2) + (len % 2))
	{
		while (apos-- > 0)
			rotate_b(stk_a, stk_b, 1);
	}
	else
	{
		while (apos++ > len)
			reverse_b(stk_a, stk_b, 1);
	}
}

void	sort_full(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	push_b(stk_a, stk_b, 1);
	push_b(stk_a, stk_b, 1);
	if ((*stk_b)->num > (*stk_b)->next->num)
	{
		limits->max = (*stk_b)->num;
		limits->min = (*stk_b)->next->num;
	}
	else
	{
		limits->max = (*stk_b)->next->num;
		limits->min = (*stk_b)->num;
	}
	algorithm(stk_a, stk_b, limits);
}
