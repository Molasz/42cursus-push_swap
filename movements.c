/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:47:55 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/15 12:38:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position(t_list *stk, int num, t_limits *limits)
{
	int	len;
	int	pos;

	len = stksize(stk);
	pos = 0;
	while (pos < len)
	{
		if ((num <= limits->min || num >= limits->max) && stk->num == limits->max)
			break ;
		if (num < stk->prev->num && num > stk->num)
			break ;
		pos++;
		stk = stk->next;
	}
	return (pos);
}

static int	lowest_movement(int posA, int posB, int lenA, int lenB)
{
	int	rr;
	int	rrr;
	int	rarrb;
	int	rrarb;

	rr = max_move(posA, posB);
	rrr = max_move(lenA - posA, lenB - posB);
	rarrb = posA + (lenB - posB);
	rrarb = (lenA - posA) + posB;
	if (rr < rrr && rr < rarrb && rr < rrarb)
		return (rr);
	if (rrr < rr && rrr < rarrb && rrr < rrarb)
		return (rrr);
	if (rarrb < rr && rarrb < rrr && rarrb < rrarb)
		return (rarrb);
	return (rrarb);
}

static int	op_movement(int posA, int posB, int lenA, int lenB)
{
	int	rr;
	int	rrr;
	int	rarrb;
	int	rrarb;

	rr = max_move(posA, posB);
	rrr = max_move(lenA - posA, lenB - posB);
	rarrb = posA + (lenB - posB);
	rrarb = (lenA - posA) + posB;
	if (rr < rrr && rr < rarrb && rr < rrarb)
		return (0);
	if (rrr < rr && rrr < rarrb && rrr < rrarb)
		return (1);
	if (rarrb < rr && rarrb < rrr && rarrb < rrarb)
		return (2);
	return (3);
}

void	calc_movements(t_list *stk_a, t_list *stk_b, t_limits *limits)
{
	int	lena;
	int	lenb;
	int	posa;
	int	posb;

	lena = stksize(stk_a);
	lenb = stksize(stk_b);
	posa = 0;
	while (posa < lena)
	{
		posb = check_position(stk_b, stk_a->num, limits);
		stk_a->posa = posa;
		stk_a->posb = posb;
		stk_a->moves = lowest_movement(posa, posb, lena, lenb);
		stk_a->op = op_movement(posa, posb, lena, lenb);
		stk_a = stk_a->next;
		posa++;
	}
}
