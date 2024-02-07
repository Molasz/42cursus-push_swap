/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:27:38 by molasz            #+#    #+#             */
/*   Updated: 2024/02/06 19:12:41 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (*src)
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		if (*dst)
		{
			tmp = (*dst)->prev;
			(*dst)->prev->next = *src;
			(*dst)->prev = *src;
			(*src)->next = *dst;
			(*src)->prev = tmp;
		}
		else
		{
			(*src)->next = *src;
			(*src)->prev = *src;
		}
		*dst = *src;
		if ((*src)->next == *src)
			*src = NULL;
		else
			*src = (*src)->next;
	}
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
