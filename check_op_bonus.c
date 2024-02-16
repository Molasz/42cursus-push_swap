/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:55:13 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/16 21:46:36 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_opr(char *op, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strncmp(op, "ra\n", 3))
		rotate_a(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate_b(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "rr\n", 3))
		rotate_ab(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "rra\n", 4))
		reverse_a(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "rrb\n", 4))
		reverse_b(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "rrr\n", 4))
		reverse_ab(stk_a, stk_b, 0);
	else
	{
		on_error();
		free_stk(*stk_a);
		free_stk(*stk_b);
		exit(1);
	}
}

static void	check_op(char *op, t_list **stk_a, t_list **stk_b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap_a(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap_b(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "ss\n", 3))
		swap_ab(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "pa\n", 3))
		push_a(stk_a, stk_b, 0);
	else if (!ft_strncmp(op, "pb\n", 3))
		push_b(stk_a, stk_b, 0);
	else
		check_opr(op, stk_a, stk_b);
}

static void	free_stks(t_list *stk_a, t_list *stk_b)
{
	free_stk(stk_a);
	free_stk(stk_b);

}

void	check(t_list *stk_a)
{
	t_list	*stk_b;
	char	*op;
	char	*op_last;
	int		end;

	stk_b = NULL;
	op = NULL;
	op_last = NULL;
	end = 0;
	while (!end)
	{
		op = get_next_line(0);
		if (!op && !op_last)
			end = 1;
		if (op)
			check_op(op, &stk_a, &stk_b);
		if (op_last)
			free(op_last);
		op_last = op;
	}
	if (is_sorted(stk_a) && !stk_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stks(stk_a, stk_b);
}
