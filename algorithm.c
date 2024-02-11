/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/11 13:29:49 by molasz-a         ###   ########.fr       */
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

static int	calc_move(int num, t_list *stk_b, int min, int max)
{
	t_list	*tmp;
	int		size;
	int		len;

	size = 0;
	tmp = stk_b;
	len = stksize(stk_b);
	while (size < len)
	{
		if (num < min && tmp->prev->num == min)
			return (size);
		if (num > max && tmp->num == max)
			return (size);
		if (num < tmp->prev->num && num > tmp->num)
			return (size);
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static void	update_moves(t_list *stk_a, t_list *stk_b, int min, int max)
{
	int	len;
	int	i;

	len = stksize(stk_a);
	i = 0;
	while (i < len)
	{
		stk_a->moves = calc_move(stk_a->num, stk_b, min, max);
		stk_a = stk_a->next;
		i++;
	}
}

static void	find_low(t_list **stk_a)
{
	t_list	*tmp;
	int		len;
	int		lown;
	int		lowp;
	int		i;

	len = stksize(*stk_a);
	i = 0;
	lown = (*stk_a)->moves;
	tmp = *stk_a;
	while (i < len)
	{
		if (tmp->moves <= lown + i)
		{
			lown = tmp->moves;
			lowp = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (lowp < (len / 2) + 1)
	{
		while (lowp-- > 0)
			rotate_a(stk_a);
	}
	else
	{
		lowp = len - lowp + 1;
		while (lowp-- > 1)
			reverse_a(stk_a);
	}
}

static void	put_n(t_list **stk_a, t_list **stk_b, int min, int max)
{
	int	moves;
	int	len;

	len = stksize(*stk_b);
	moves = calc_move((*stk_a)->num, *stk_b, min, max);
	if (moves < (len / 2) + 1)
	{
		while (moves-- > 0)
			rotate_b(stk_b);
	}
	else
	{
		moves = len - moves + 1;
		while (moves-- > 1)
			reverse_b(stk_b);
	}
	push_b(stk_b, stk_a);
}

void	algorithm(t_list **stk_a, t_list **stk_b)
{
	int	max;
	int	min;

	min = (*stk_a)->num;
	max = (*stk_a)->num;
	push_b(stk_b, stk_a);
	while (*stk_a)
	{
		update_moves(*stk_a, *stk_b, min, max);
		find_low(stk_a);
		put_n(stk_a, stk_b, min, max);
		if (max <= (*stk_b)->num)
			max = (*stk_b)->num;
		if (min >= (*stk_b)->num)
			min = (*stk_b)->num;
		//print_stks(*stk_a, *stk_b);
	}
	while ((*stk_b)->num != max)
		rotate_b(stk_b);
	while (*stk_b)
		push_a(stk_a, stk_b);
}
