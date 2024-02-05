/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:36:13 by molasz            #+#    #+#             */
/*   Updated: 2024/02/06 00:00:13 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_r(t_list **lst, t_list *stk)
{
	if (stk)
	{
		rotate_r(lst, stk->next);
		ft_lstadd_front(lst, stk);
	}
}

static void	rotate(t_list **stk)
{
	t_list	 *lst;

	if (ft_lstsize(*stk))
	{
		ft_lstadd_front(&lst, *stk);
		rotate_r(&lst, (*stk)->next);
		*stk = lst;
	}
}

void	rotate_a(t_list **stk)
{
	rotate(stk);
	write(1, "ra", 2);
}

void	rotate_b(t_list **stk)
{
	rotate(stk);
	write(1, "rb", 2);
}

void	rotate_ab(t_list **stk_a, t_list **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	write(1, "rr", 2);
}
