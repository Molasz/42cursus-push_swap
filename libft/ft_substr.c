/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:41:41 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/09 15:56:08 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;

	if (ft_strlen(str) < start)
		len = 0;
	else if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	substr = ft_calloc(sizeof (char), len + 1);
	if (!substr)
		return (NULL);
	if (len)
		ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
