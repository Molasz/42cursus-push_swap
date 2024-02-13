/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:04:55 by molasz            #+#    #+#             */
/*   Updated: 2024/02/13 21:32:16 by molasz-a         ###   ########.fr       */
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

typedef struct s_limits
{
	int	max;
	int	min;
}				t_limits;

int		on_error(void);
int		free_numsstr(char **numsstr);
t_list	*free_stk(t_list *stk, int len);
t_list	*get_stk(int *nums, int len);

int		sort(t_list *stk);
void	order(t_list **stk_a, t_list **stk_b, t_limits *limits);

void	sort_full(t_list **stk_a, t_list **stk_b, t_limits *limits);
void	push_num(int num, t_list **stk_a, t_list **stk_b, t_limits *limits);
int		stksize(t_list *stk);
int		abs_move(int n);
int		max_move(int n1, int n2);
int		calc_move(int num, t_list *stk_b, t_limits *limits);

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
