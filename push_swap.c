/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz <molasz-a@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 00:05:26 by molasz            #+#    #+#             */
/*   Updated: 2024/02/10 17:29:24 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_numsstr(int argc, char **argv)
{
	char	**numsstr;
	char	*str;
	char	*tmp;

	if (argc > 2)
		return (argv + 1);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	tmp = get_next_line(0);
	if (!tmp)
		return (NULL);
	str = ft_strtrim(tmp, "\n");
	free(tmp);
	if (!str)
		return (NULL);
	numsstr = ft_split(str, ' ');
	free(str);
	return (numsstr);
}

static int	check_numsstr(char **nums)
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
	nums = ft_calloc(sizeof (int), i);
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

static int	check_nums(int *nums, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (nums[j])
		{
			if (i != j && nums[j] == nums[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**numsstr;
	int		*nums;
	int		len;
	t_list	*stk;

	numsstr = get_numsstr(argc, argv);
	if (!numsstr || check_numsstr(numsstr))
		return (on_error());
	len = 0;
	nums = get_nums(numsstr);
	if (argc < 3)
		len = free_numsstr(numsstr);
	else
		len = argc - 1;
	if (!nums || check_nums(nums, len))
		return (on_error());
	stk = get_stk(nums, len);
	sort(stk);
	free(nums);
	return (0);
}
