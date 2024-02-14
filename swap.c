/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:47 by molasz            #+#    #+#             */
/*   Updated: 2024/02/14 00:01:21 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stk)
{
	int	num;

	if (stk)
	{
		num = stk->next->num;
		stk->next->num = stk->num;
		stk->num = num;
	}
}

void	swap_a(t_list **stk_a, t_list **stk_b)
{
	swap(*stk_a);
	if (write(1, "sa\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	swap_b(t_list **stk_a, t_list **stk_b)
{
	swap(*stk_b);
	if (write(1, "sb\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	swap_ab(t_list **stk_a, t_list **stk_b)
{
	swap(*stk_a);
	swap(*stk_b);
	if (write(1, "ss\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}
