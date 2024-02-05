/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:49:07 by molasz            #+#    #+#             */
/*   Updated: 2024/02/05 23:59:39 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    reverse_r(t_list **lst, t_list *stk)
{
        if (stk && stk->next)
        {
                reverse_r(lst, stk->next);
                ft_lstadd_front(lst, stk);
        }
}

static void	reverse(t_list **stk)
{
	t_list	*lst;
	t_list	*tmp;

	if (ft_lstsize(*stk))
	{
		reverse_r(&lst, *stk);
		tmp = ft_lstlast(*stk);
		ft_lstadd_front(&lst, tmp);

	}
}
void	reverse_a(t_list **stk)
{
	reverse(stk);
	write(1, "rra", 3);
}

void	reverse_b(t_list **stk)
{
	reverse(stk);
	write(1, "rrb", 3);
}

void	reverse_ab(t_list **stk_a, t_list **stk_b)
{
	reverse(stk_a);
	reverse(stk_b);
	write(1, "rrr", 3);
}
