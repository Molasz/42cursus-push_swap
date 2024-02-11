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
		printf("A: %d, ", stk_a->num);
		tmp = stk_a->next;
		while (stk_a != tmp)
		{
			printf("%d, ", tmp->num);
			tmp = tmp->next;
		}
		printf("\n");
	}
	if (stk_b)
	{
		printf("B: %d, ", stk_b->num);
		tmp = stk_b->next;
		while (stk_b != tmp)
		{
			printf("%d, ", tmp->num);
			tmp = tmp->next;
		}
		printf("\n");
	}
	printf("\n\n\n");
}
