/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:21:47 by molasz            #+#    #+#             */
/*   Updated: 2024/02/06 00:00:38 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stk)
{
	int	*n;

	if (stk)
	{
		n = stk->next->content;
		stk->next->content = stk->content;
		stk->content = n;
	}
}

void	swap_a(t_list *stk)
{
	swap(stk);
	write(1, "sa\n", 3);
}

void	swap_b(t_list *stk)
{
	swap(stk);
	write(1, "sb\n", 3);
}

void	swap_ab(t_list *stk_a, t_list *stk_b)
{
	swap(stk_a);
	swap(stk_b);
	write(1, "ss\n", 3);
}
