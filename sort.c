/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:05 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/08 17:34:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stks(t_list	*stk_a, t_list	*stk_b)
{
	t_list	*tmp;

	printf("A: %d, ", *(int *)stk_a->content);
	if (stk_a)
	{
		tmp = stk_a->next;
		while (stk_a != tmp)
		{
			printf("%d, ", *(int *)tmp->content);
			tmp = tmp->next;
		}
	}
	printf("\nB: %d, ", *(int *)stk_b->content);
	if (stk_b)
	{
		tmp = stk_b->next;
		while (stk_b != tmp)
		{
			printf("%d, ", *(int *)tmp->content);
			tmp = tmp->next;
		}
	}
	printf("\n");
}

int	sort(t_list	*stk_a)
{
	t_list	*stk_b;
	int		max;
	int		count;

	stk_b = NULL;
	max = INT_MIN;
	count = 0;
	while (count++ != 15)
	{
		if(max < *(int *)stk_a->content)
		{
			max = *(int *)stk_a->content;
			push_b(&stk_b, &stk_a);
			rotate_b(&stk_b);
		}
		else if (*(int *)stk_a->content < *(int *)stk_b->content)
			push_b(&stk_b, &stk_a);
		else
			rotate_a(&stk_a);
		print_stks(stk_a, stk_b);
	}
	return (0);
}
