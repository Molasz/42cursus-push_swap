/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:36:13 by molasz            #+#    #+#             */
/*   Updated: 2024/02/14 00:00:53 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stk)
{
	*stk = (*stk)->next;
}

void	rotate_a(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	if (write(1, "ra\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	rotate_b(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_b);
	if (write(1, "rb\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	rotate_ab(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	if (write(1, "rr\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}
