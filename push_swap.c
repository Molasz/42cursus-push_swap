/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:05:26 by molasz            #+#    #+#             */
/*   Updated: 2024/02/06 16:56:12 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*snums;
	char	**nums;

	if (argc == 1)
	{
		snums = get_next_line(0);
		if (!snums)
			return (-1);
		nums = ft_split(snums, ' ');
		free(snums);
	}
	else if (argc == 2)
	{
		snums = argv[1];
		nums = ft_split(snums, ' ');
	}
	else
		nums = argv + 1;
	if (!nums)
		return (-1);
	if (argc < 3)
		free(nums);
	return (0);
}
