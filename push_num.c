/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/15 02:05:01 by molasz-a         ###   ########.fr       */
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
	int	lena;
	int	lenb;

	lena = stksize(*stk_a);
	lenb = stksize(*stk_b);
	while (apos < lena && bpos < lenb)
	{
		reverse_ab(stk_a, stk_b);
		apos++;
		bpos++;
	}
	while (apos++ < lena)
		reverse_a(stk_a, stk_b);
	while (bpos++ < lenb)
		reverse_b(stk_a, stk_b);
}

void	push_reverse(int apos, int bpos, t_list **stk_a, t_list **stk_b)
{
	int	lenb;

	lenb = stksize(*stk_b);
	while (apos-- > 0)
		rotate_a(stk_a, stk_b);
	while (bpos++ < lenb)
		reverse_b(stk_a, stk_b);
}

void	push_back_front(int apos, int bpos, t_list **stk_a, t_list **stk_b)
{
	int	lena;

	lena = stksize(*stk_a);
	while (apos++ < lena)
		reverse_a(stk_a, stk_b);
	while (bpos-- > 0)
		rotate_b(stk_a, stk_b);
}

void	push_num(int posA, t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = *stk_a;
	while (count++ < posA)
		tmp = tmp->next;
	if (tmp->op == 0)
		push_front(tmp->posa, tmp->posb, stk_a, stk_b);
	else if (tmp->op == 1)
		push_back(tmp->posa, tmp->posb, stk_a, stk_b);
	else if (tmp->op == 2)
		push_reverse(tmp->posa, tmp->posb, stk_a, stk_b);
	else
		push_back_front(tmp->posa, tmp->posb, stk_a, stk_b);
	push_b(stk_a, stk_b);
}
