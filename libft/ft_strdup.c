/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 23:35:48 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/09 15:57:38 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*str;

	src_len = ft_strlen(src);
	str = ft_calloc(sizeof (char), src_len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, src_len + 1);
	return (str);
}
