/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/10 19:16:47 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list	*stk)
{
	t_list	*tmp;

	tmp = stk->next;
	while (stk != tmp)
	{
		if (*(int *)tmp->prev->content > *(int *)tmp->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	sort(t_list	*stk_a)
{
	t_list	*stk_b;

	stk_b = NULL;
	if (is_sorted(stk_a))
		return (0);
	algorithm(&stk_a, &stk_b, INT_MIN, INT_MAX);
	//print_stks(stk_a, stk_b);
	return (0);
}
