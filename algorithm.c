/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/13 14:42:26 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_moves(t_list *stk_a, t_list *stk_b, t_limits *limits)
{
	int	bpos;
	int	apos;
	int	len;
	int	i;

	len = stksize(stk_a);
	i = 0;
	while (i < len)
	{
		bpos = calc_move(stk_a->num, stk_b, limits);
		if (i > len / 2)
			apos = i - len;
		else
			apos = i;
		if ((apos >= 0 && bpos >= 0) || (apos < 0 && bpos < 0))
			stk_a->moves = max_move(apos, bpos);
		else
			stk_a->moves = abs(apos) + abs(bpos);
		stk_a = stk_a->next;
		i++;
	}
}

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

static void	order_stk(t_list **stk_b, int max)
{
	t_list	*tmp;
	int		len;
	int		i;

	len = stksize(*stk_b);
	tmp = *stk_b;
	i = 0;
	while (tmp->num != max)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < (len / 2) + 1)
	{
		while (i-- > 0)
			rotate_b(stk_b);
	}
	else
	{
		i = len - i + 1;
		while (i-- > 1)
			reverse_b(stk_b);
	}
}

void	algorithm(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	int	apos;

	while (stksize(*stk_a) > 3)
	{
		update_moves(*stk_a, *stk_b, limits);
		apos = find_low(stk_a);
		push_num(apos, stk_a, stk_b, limits);
		if (limits->max < (*stk_b)->num)
			limits->max = (*stk_b)->num;
		if (limits->min > (*stk_b)->num)
			limits->min = (*stk_b)->num;
	}
	order_stk(stk_b, limits->max);
}
