/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:03:19 by molasz            #+#    #+#             */
/*   Updated: 2024/02/05 20:47:18 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_list *stk)
{
	int	*n;

	if (ft_lstsize(stk) > 1)
	{
		n = stk->next->content;
		stk->next->content = stk->content;
		stk->content = n;
	}
}

void	op_push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (ft_lstsize(*src))
	{
		ft_lstadd_front(dst, *src);

		tmp = (*src)->next;
		ft_lstdelone(*src, NULL);
		*src = tmp;
	}
}

void	op_rotate_r(t_list **lst, t_list *stk)
{
	if (stk)
	{
		op_rotate_r(lst, stk->next);
		ft_lstadd_front(lst, stk);
	}
}

void	op_rotate(t_list **stk)
{
	t_list	*lst;

	if (ft_lstsize(*stk))
	{
		ft_lstadd_front(&lst, *stk);
		*stk = (*stk)->next;
		op_rotate_r(&lst, *stk);
		*stk = lst;
	}
}

void	op_reverse(t_list **stk)
{
	t_list	*lst;
	t_list	*stk_tmp;

	if (ft_lstsize(*stk))
	{
		while (*stk)
		{
			stk_tmp = *stk;
			ft_lstadd_front(&lst, stk_tmp);
			*stk = (*stk)->next;
		}
		*stk = lst;
	}
}
