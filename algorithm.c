/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/14 12:42:31 by molasz-a         ###   ########.fr       */
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
			stk_a->moves = abs_move(apos) + abs_move(bpos);
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

static void	algorithm(t_list **stk_a, t_list **stk_b, t_limits *limits)
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
}

void	sort_full(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	push_b(stk_a, stk_b);
	push_b(stk_a, stk_b);
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
