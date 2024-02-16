/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:16:09 by molasz-a          #+#    #+#             */
/*   Updated: 2024/02/16 01:37:34 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <unistd.h> 
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
long	ft_atoi(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif
