/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:35:34 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/09 15:46:55 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*mem;

	mem = (void *)malloc(nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
		((char *)mem)[i++] = 0;
	return (mem);
}
