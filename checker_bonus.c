/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:55:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/16 00:53:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_str(char *str)
{
	int	i;
	int	zeros;
	int	num;

	i = 0;
	zeros = 0;
	num = 0;
	while (str[i])
	{
		if ((str[i] != '+' && str[i] != '-')
			&& (str[i] < '0' || str[i] > '9'))
			return (1);
		if ((str[i] == '+' || str[i] == '-') && i)
			return (1);
		if (str[i] == '0')
			zeros++;
		if (str[i] >= '0' && str[i] <= '9')
			num = 1;
		i++;
	}
	if (i - zeros > 11 || i == 0 || !num)
		return (1);
	return (0);
}

static int	check_numsstr(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		if (check_str(nums[i]))
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
		while (j < len)
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
	int		*nums;
	int		len;
	t_list	*stk;

	if (argc < 2 || check_numsstr(argv + 1))
		return (on_error());
	len = 0;
	nums = get_nums(argv + 1);
	len = argc - 1;
	if (!nums || check_nums(nums, len))
		return (on_error());
	stk = get_stk(nums, len);
	check(stk);
	free(nums);
	return (0);
}
