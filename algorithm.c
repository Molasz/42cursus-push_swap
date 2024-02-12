/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/12 20:09:16 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stksize(t_list *stk)
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

static int	calc_move(int num, t_list *stk_b, t_limit limit)
{
	t_list	*tmp;
	int		size;
	int		len;

	size = 0;
	tmp = stk_b;
	len = stksize(stk_b);
	while (size < len)
	{
		if (num < limit.min && tmp->num == limit.max)
			return (size);
		if (num > limit.max && tmp->num == limit.max)
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

static void	update_moves(t_list *stk_a, t_list *stk_b, t_limit limit)
{
	int	bpos;
	int	apos;
	int	len;
	int	i;

	len = stksize(stk_a);
	i = 0;
	while (i < len)
	{
		bpos = calc_move(stk_a->num, stk_b, limit);
		if (i > (len / 2) + 1)
			apos = i - len;
		else
			apos = i;
		if ((apos > 0 && bpos > 0) || (apos < 0 && bpos < 0))
			stk_a->moves = max_move(apos, bpos);
		else
			stk_a->moves = abs(apos) + abs(bpos);
		stk_a = stk_a->next;
		i++;
	}
	print_stks(stk_a, stk_b);
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

static void	put_n(int apos, t_list **stk_a, t_list **stk_b, t_limit limit)
{
	t_list	*tmp;
	int		bpos;
	int		alen;
	int		i;

	tmp = *stk_a;
	i= 0;
	while (apos < i)
		tmp = tmp->next;
	bpos = calc_move(tmp->num, *stk_b, limit);
	
	alen = stksize(*stk_a);
	if (apos > (alen / 2) + 1)
		apos -= alen;
	printf("A:%d B:%d\n", apos, bpos);
	if (apos > 0 && bpos > 0)
	{
		while (apos-- > 0 && bpos-- > 0)
			rotate_ab(stk_a, stk_b);
		while (apos-- > 0)
			rotate_a(stk_a);
		while (bpos-- > 0)
			rotate_b(stk_a);
	}
	else if (apos < 0 && bpos < 0)
	{
		while (apos++ < 0 && bpos++ < 0)
			reverse_ab(stk_a, stk_b);
		while (apos++ < 0)
			reverse_a(stk_a);
		while (bpos++ < 0)
			reverse_b(stk_b);
	}
	else if (apos > 0 && bpos < 0)
	{
		while (apos-- > 0)
			rotate_a(stk_a);
		while (bpos++ < 0)
			reverse_b(stk_b);
	}
	else if (apos < 0 && bpos > 0)
	{
		while (apos++ < 0)
			reverse_a(stk_a);
		while (bpos-- > 0)
			rotate_b(stk_b);
	}
	push_b(stk_b, stk_a);
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

void	algorithm(t_list **stk_a, t_list **stk_b)
{
	t_limit	limit;
	int	apos;

	limit.min = (*stk_a)->num;
	limit.max = (*stk_a)->num;
	push_b(stk_b, stk_a);
	while (*stk_a)
	{
		update_moves(*stk_a, *stk_b, limit);
		apos = find_low(stk_a);
		put_n(apos, stk_a, stk_b, limit);
		if (limit.max <= (*stk_b)->num)
			limit.max = (*stk_b)->num;
		if (limit.min >= (*stk_b)->num)
			limit.min = (*stk_b)->num;
	//print_stks(*stk_a, *stk_b);
	}
	order_stk(stk_b, limit.max);
	while (*stk_b)
		push_a(stk_a, stk_b);
}
