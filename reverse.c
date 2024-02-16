/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:49:07 by molasz            #+#    #+#             */
/*   Updated: 2024/02/16 21:56:29 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_list **stk)
{
	if (*stk)
		*stk = (*stk)->prev;
}

void	reverse_a(t_list **stk_a, t_list **stk_b, int w)
{
	reverse(stk_a);
	if (!w)
		return ;
	if (write(1, "rra\n", 4) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	reverse_b(t_list **stk_a, t_list **stk_b, int w)
{
	reverse(stk_b);
	if (!w)
		return ;
	if (write(1, "rrb\n", 4) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	reverse_ab(t_list **stk_a, t_list **stk_b, int w)
{
	reverse(stk_a);
	reverse(stk_b);
	if (!w)
		return ;
	if (write(1, "rrr\n", 4) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}
