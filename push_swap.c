/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:05:26 by molasz            #+#    #+#             */
/*   Updated: 2024/02/06 00:08:56 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "INPUT\n", 6);
	else if (argc == 2)
		write(1, "STR\n", 4);
	else
	{
		(void)argv;;
	}
	return (0);
}
