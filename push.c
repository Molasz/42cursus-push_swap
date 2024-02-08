/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:27:38 by molasz            #+#    #+#             */
/*   Updated: 2024/02/08 17:20:25 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

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

void	push_a(t_list **dst, t_list **src)
{
	push(dst, src);
	write(1, "pa\n", 3);
}

void	push_b(t_list **dst, t_list **src)
{
	push(dst, src);
	write(1, "pb\n", 3);
}
