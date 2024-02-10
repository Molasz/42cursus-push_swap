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
	tmp = stk->prev;
	while (stk != tmp)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

static void	put_front(t_list **stk_a, t_list **stk_b, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		rotate_b(stk_b);
	push_b(stk_b, stk_a);
	i = 0;
	while (i++ < count)
		reverse_b(stk_b);
}

static void	put_back(t_list **stk_a, t_list **stk_b, int count)
{
	int	i;

	i = 0;
	while (i++ < count)
		reverse_b(stk_b);
	push_b(stk_b, stk_a);
	i = 0;
	while (i++ < count + 1)
		rotate_b(stk_b);
}

static void	put_n(t_list **stk_a, t_list **stk_b)
{
	t_list	*tmp;
	int		front;
	int		back;
	int		len;

	len = stksize(*stk_b);
	tmp = *stk_b;
	front = 0;
	while (*(int *)(*stk_a)->content < *(int *)tmp->content)
	{
		front++;
		tmp = tmp->next;
	}
	tmp = (*stk_b)->prev;
	back = 0;
	while (*(int *)(*stk_a)->content > *(int *)tmp->content)
	{
		back++;
		tmp = tmp->prev;
	}
	if (front < (len / 2) + 1)
		put_front(stk_a, stk_b, front);
	else
		put_back(stk_a, stk_b, back);
}

void	algorithm(t_list **stk_a, t_list **stk_b, int max, int min)
{
	while (*stk_a)
	{
		if (max <= *(int *)(*stk_a)->content)
		{
			max = *(int *)(*stk_a)->content;
			push_b(stk_b, stk_a);
		}
		else if (min >= *(int *)(*stk_a)->content)
		{
			min = *(int *)(*stk_a)->content;
			push_b(stk_b, stk_a);
			rotate_b(stk_b);
		}
		else
			put_n(stk_a, stk_b);
	}
	while (*stk_b)
		push_a(stk_a, stk_b);
}
