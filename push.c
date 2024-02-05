/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:27:38 by molasz            #+#    #+#             */
/*   Updated: 2024/02/05 23:58:57 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	if (ft_lstsize(*src))
	{
		ft_lstadd_front(dst, *src);
		*src = (*src)->next;
	}
}

void	push_a(t_list **dst, t_list **src)
{
	push(dst, src);
	write(1, "pa", 2);
}

void	push_b(t_list **dst, t_list **src)
{
	push(dst, src);
	write(1, "pb", 2);
}
