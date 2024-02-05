/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:17:13 by molasz-a          #+#    #+#             */
/*   Updated: 2023/11/20 22:21:38 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static unsigned int	ft_abs(int n, int *size)
{
	unsigned int	num;

	num = (unsigned int)n;
	if (n < 0)
	{
		num = (unsigned int)-n;
		*size += 1;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*str;
	int				str_size;
	int				str_count;

	str_size = 0;
	num = ft_abs(n, &str_size);
	str_size += num_len(num);
	str = ft_calloc(sizeof (char), str_size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str_count = str_size - 1;
	while ((n >= 0 && str_count >= 0) || (n < 0 && str_count))
	{
		str[str_count] = (num % 10) + '0';
		num /= 10;
		str_count--;
	}
	return (str);
}
