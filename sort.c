/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/14 00:56:07 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_list	*stk)
{
	t_list	*tmp;

	tmp = stk->next;
	while (stk != tmp)
	{
		if (tmp->prev->num > tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static	void	sort_three(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	if ((*stk_a)->num > (*stk_a)->next->num
		&& (*stk_a)->num > (*stk_a)->prev->num)
		rotate_a(stk_a, stk_b);
	else if ((*stk_a)->num < (*stk_a)->next->num
		&& (*stk_a)->next->num > (*stk_a)->prev->num)
		reverse_a(stk_a, stk_b);
	if (!is_sorted(*stk_a))
		swap_a(stk_a, stk_b);
	limits->max = (*stk_a)->prev->num;
	limits->min = (*stk_a)->num;
}

static void	sort_final(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	while (*stk_b)
	{
		if ((*stk_b)->num > limits->max || (*stk_b)->num < limits->min)
		{
			while ((*stk_a)->num != limits->min)
				reverse_a(stk_a, stk_b);
			if ((*stk_b)->num > limits->max)
				limits->max = (*stk_b)->num;
			else
				limits->min = (*stk_b)->num;
			push_a(stk_a, stk_b);
		}
		else if ((*stk_a)->num > (*stk_b)->num
			&& (*stk_a)->prev->num < (*stk_b)->num)
			push_a(stk_a, stk_b);
		else
			reverse_a(stk_a, stk_b);
	}
}

void	order(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	t_list	*tmp;
	int		count;
	int		len;

	len = stksize(*stk_a);
	count = 0;
	tmp = *stk_a;
	while (tmp->num != limits->min)
	{
		count++;
		tmp = tmp->next;
	}
	if (count < len / 2)
	{
		while (count-- > 0)
			rotate_a(stk_a, stk_b);
	}
	else
	{
		count = len - count;
		while (count-- > 0)
			reverse_a(stk_a, stk_b);
	}
}

int	sort(t_list	*stk_a)
{
	t_list		*stk_b;
	t_limits	limits;

	stk_b = NULL;
	limits.max = INT_MIN;
	limits.min = INT_MAX;
	if (!is_sorted(stk_a))
	{
		if (stksize(stk_a) > 3)
			sort_full(&stk_a, &stk_b, &limits);
		sort_three(&stk_a, &stk_b, &limits);
		sort_final(&stk_a, &stk_b, &limits);
		order(&stk_a, &stk_b, &limits);
	}
	free_stk(stk_a);
	free_stk(stk_b);
	return (0);
}
