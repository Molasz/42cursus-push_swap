/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:27:38 by molasz            #+#    #+#             */
/*   Updated: 2024/02/14 00:04:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	(*src)->moves = 0;
	(*src)->next->prev = (*src)->prev;
	(*src)->prev->next = (*src)->next;
	if (*src == (*src)->next)
		tmp = NULL;
	else
		tmp = (*src)->next;
	if (*dst)
	{
		(*src)->next = *dst;
		(*src)->prev = (*dst)->prev;
		(*dst)->prev->next = *src;
		(*dst)->prev = *src;
		*dst = *src;
	}
	else
	{
		(*src)->next = *src;
		(*src)->prev = *src;
		*dst = *src;
	}
	*src = tmp;
}

void	push_a(t_list **stk_a, t_list **stk_b)
{
	push(stk_a, stk_b);
	if (write(1, "pa\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

void	push_b(t_list **stk_a, t_list **stk_b)
{
	push(stk_b, stk_a);
	if (write(1, "pb\n", 3) < 0)
	{
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}
