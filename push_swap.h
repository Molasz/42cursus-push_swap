/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:04:55 by molasz            #+#    #+#             */
/*   Updated: 2024/02/11 12:15:23 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				num;
	int				moves;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int		on_error(void);
int		free_numsstr(char **numsstr);
t_list	*free_stk(t_list *stk, int len);
t_list	*get_stk(int *nums, int len);

int		sort(t_list *stk);

void	algorithm(t_list **stk_a, t_list **stk_b);

void	swap_a(t_list *stk);
void	swap_b(t_list *stk);
void	swap_ab(t_list *stk_a, t_list *stk_b);
void	push_a(t_list **dst, t_list **src);
void	push_b(t_list **dst, t_list **src);
void	rotate_a(t_list **stk);
void	rotate_b(t_list **stk);
void	rotate_ab(t_list **stk_a, t_list **stk_b);
void	reverse_a(t_list **stk);
void	reverse_b(t_list **stk);
void	reverse_ab(t_list **stk_a, t_list **stk_b);

void	print_stks(t_list	*stk_a, t_list	*stk_b);

#endif
