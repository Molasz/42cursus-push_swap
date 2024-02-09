/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:16:32 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/09 18:16:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stks(t_list	*stk_a, t_list	*stk_b)
{
	t_list	*tmp;

	if (stk_a)
	{
		printf("A: %d, ", *(int *)stk_a->content);
		tmp = stk_a->next;
		while (stk_a != tmp)
		{
			printf("%d, ", *(int *)tmp->content);
			tmp = tmp->next;
		}
		printf("\n");
	}
	if (stk_b)
	{
		printf("B: %d, ", *(int *)stk_b->content);
		tmp = stk_b->next;
		while (stk_b != tmp)
		{
			printf("%d, ", *(int *)tmp->content);
			tmp = tmp->next;
		}
		printf("\n");
	}
}
