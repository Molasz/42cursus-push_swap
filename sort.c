/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/13 16:02:50 by molasz-a         ###   ########.fr       */
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

static	void	sort_full(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	push_b(stk_b, stk_a);
	push_b(stk_b, stk_a);
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

static	void	sort_three(t_list **stk_a, t_limits *limits)
{
	if ((*stk_a)->num > (*stk_a)->next->num
		&& (*stk_a)->num > (*stk_a)->prev->num)
		rotate_a(stk_a);
	else if ((*stk_a)->num < (*stk_a)->next->num
		&& (*stk_a)->next->num > (*stk_a)->prev->num)
		reverse_a(stk_a);
	if (!is_sorted(*stk_a))
		swap_a(*stk_a);
	limits->max = (*stk_a)->prev->num;
	limits->min = (*stk_a)->num;
}

void	sort_final(t_list **stk_a, t_list **stk_b, t_limits *limits)
{
	while (*stk_b)
	{
		if ((*stk_b)->num > limits->max || (*stk_b)->num < limits->min)
		{
			while ((*stk_a)->num != limits->min)
				reverse_a(stk_a);
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
			rotate_a(stk_a);
	}
}

int	sort(t_list	*stk_a)
{
	t_list		*stk_b;
	t_limits	limits;

	stk_b = NULL;
	limits.max = INT_MIN;
	limits.min = INT_MAX;
	if (is_sorted(stk_a))
		return (0);
	if (stksize(stk_a) > 3)
		sort_full(&stk_a, &stk_b, &limits);
	sort_three(&stk_a, &limits);
	sort_final(&stk_a, &stk_b, &limits);
	free_stk(stk_a, stksize(stk_a));
	free_stk(stk_b, stksize(stk_b));
	return (0);
}
