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

void	print_stk(t_list	*stk)
{
	t_list	*tmp;

	printf("STK: %d ", *(int *)stk->content);
	tmp = stk->next;
	while (stk != tmp)
	{
		printf("%d, ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

int	sort(t_list	*stk_a)
{
	t_list	*stk_b;

	stk_b = NULL;
	print_stk(stk_a);
	swap_a(stk_a);
	print_stk(stk_a);
	rotate_a(&stk_a);
	print_stk(stk_a);
	swap_a(stk_a);
	print_stk(stk_a);
	push_b(&stk_b, &stk_a);
	print_stk(stk_a);
	print_stk(stk_b);
	push_b(&stk_b, &stk_a);
	print_stk(stk_a);
	print_stk(stk_b);
	push_b(&stk_b, &stk_a);
	print_stk(stk_a);
	print_stk(stk_b);
	push_b(&stk_b, &stk_a);
	print_stk(stk_a);
	print_stk(stk_b);
	push_b(&stk_b, &stk_a);
	print_stk(stk_a);
	print_stk(stk_b);
	push_a(&stk_a, &stk_b);
	print_stk(stk_a);
	print_stk(stk_b);
	return (0);
}
