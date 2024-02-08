/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:49:07 by molasz            #+#    #+#             */
/*   Updated: 2024/02/05 23:59:39 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_list **stk)
{
	*stk = (*stk)->prev;
}

void	reverse_a(t_list **stk)
{
	reverse(stk);
	write(1, "rra\n", 4);
}

void	reverse_b(t_list **stk)
{
	reverse(stk);
	write(1, "rrb\n", 4);
}

void	reverse_ab(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_a);
	reverse(stk_b);
	write(1, "rrr\n", 4);
}
