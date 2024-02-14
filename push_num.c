/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/14 00:06:50 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(int apos, int bpos, t_list **stk_a, t_list **stk_b)
{
	while (apos > 0 && bpos > 0)
	{
		rotate_ab(stk_a, stk_b);
		apos--;
		bpos--;
	}
	while (apos-- > 0)
		rotate_a(stk_a, stk_b);
	while (bpos-- > 0)
		rotate_b(stk_a, stk_b);
}

void	push_back(int apos, int bpos, t_list **stk_a, t_list **stk_b)
{
	while (apos < 0 && bpos < 0)
	{
		reverse_ab(stk_a, stk_b);
		apos++;
		bpos++;
	}
	while (apos++ < 0)
		reverse_a(stk_a, stk_b);
	while (bpos++ < 0)
		reverse_b(stk_a, stk_b);
}

void	push_reverse(int apos, int bpos, t_list **stk_a, t_list **stk_b)
{
	if (apos >= 0 && bpos < 0)
	{
		while (apos-- > 0)
			rotate_a(stk_a, stk_b);
		while (bpos++ < 0)
			reverse_b(stk_a, stk_b);
	}
	else if (apos < 0 && bpos >= 0)
	{
		while (apos++ < 0)
			reverse_a(stk_a, stk_b);
		while (bpos-- > 0)
			rotate_b(stk_a, stk_b);
	}
}

void	push_num(int apos, t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	t_list	*tmp;
	int		bpos;
	int		alen;
	int		i;

	tmp = *stk_a;
	i = 0;
	while (i++ < apos)
		tmp = tmp->next;
	bpos = calc_move(tmp->num, *stk_b, limits);
	alen = stksize(*stk_a);
	if (apos > alen / 2)
		apos -= alen;
	if (apos >= 0 && bpos >= 0)
		push_front(apos, bpos, stk_a, stk_b);
	else if (apos < 0 && bpos < 0)
		push_back(apos, bpos, stk_a, stk_b);
	else
		push_reverse(apos, bpos, stk_a, stk_b);
	push_b(stk_a, stk_b);
}
