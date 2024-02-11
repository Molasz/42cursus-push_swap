/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:59:12 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/10 18:57:33 by molasz-a         ###   ########.fr       */
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

static int	calc_move(t_list *stk_a, t_list *stk_b, int min, int max)
{
	t_list	*tmp;
	int		size;
	int		len;

	size = 0;
	tmp = stk_b;
	len = stksize(stk_b);
	while (size < len)
	{
		if (stk_a->num < min && tmp->prev->num == min)
			return (size);
		if (stk_a->num > max && tmp->num == max)
			return (size);
		if (stk_a->num < tmp->prev->num && stk_a->num > tmp->num)
			return (size);
		size++;
		tmp = tmp->next;
	}
	return (size);
}

static void	put_n(t_list **stk_a, t_list **stk_b, int min, int max)
{
	int	moves;
	int	len;

	len = stksize(*stk_b);
	moves = calc_move(*stk_a, *stk_b, min, max);
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
