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
	write(2, "ERROR\n", 6);
	return (1);
}

static char	**get_numsstr(int argc, char **argv)
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
	return (argv + 1);
}

static int check_numsstr(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		while (nums[i][j])
		{
			if (nums[i][j] != '-' && (nums[i][j] < '0' || nums[i][j] > '9'))
				return (1);
			j++;
		}
		if (j > 12)
			return (1);
		i++;
	}
	return (0);
}

static int	*get_nums(char **numsstr)
{
	int		*nums;
	long	lnum;
	int		i;

	i = 0;
	while (numsstr[i])
		i++;
	nums = ft_calloc(sizeof (int), i + 1);
	i = 0;
	while (numsstr[i])
	{
		lnum = ft_atoi(numsstr[i]);
		if (lnum > INT_MAX || lnum < INT_MIN)
			return (NULL);
		nums[i] = lnum;
		i++;
	}
	return (nums);
}

static int	check_nums(int *nums)
{
	int	i;
	int	j;
	int	low;

	low = 1;
	i = 0;
	while(nums[i])
	{
		j = 0;
		while (nums[j])
		{
			if (i != j && nums[j] == nums[i])
				return (1);
			if (i && nums[i - 1] > nums[i])
				low = 0;
			j++;
		}
		i++;
	}
	return (low);
}

int	main(int argc, char **argv)
{
	char	**numsstr;
	int		*nums;
	int		i;

	numsstr = get_numsstr(argc, argv);
	if (!numsstr || check_numsstr(numsstr))
		return (on_error());
	nums = get_nums(numsstr);
	if (argc < 2)
		free(numsstr);
	if (!nums || check_nums(nums))
		return (on_error());
	i = 0;
	while (nums[i])
	{
		printf("%d, ", nums[i]);
		i++;
	}
	printf("\n");
	//sort(nums);
	free(nums);
	return (0);
}
