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

static int	on_error()
{
	write(1, "ERROR\n", 6);
	return (1);
}

char	**get_numsstr(int argc, char **argv)
{
	char	*str;

	if (argc == 1)
	{
		str = get_next_line(0);
		if (!str)
			return (NULL);
		return (ft_split(str, ' '));
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));

}

int	main(int argc, char **argv)
{
	char	**numsstr;
	int		*nums;

	numsstr = get_numsstr(argc, argv);
	if (!numsstr || check_numsstr(numsstr))
		return (on_error());
	nums = get_nums(numsstr);
	free(numsstr);
	if (!nums || check_nums(nums))
		return (on_error());
	sort(nums);
	free(nums);
	return (0);
}
