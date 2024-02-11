# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 17:13:17 by molasz-a          #+#    #+#              #
#    Updated: 2024/02/05 19:55:15 by molasz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			get_next_line_utils.c

HEAD	= libft.h get_next_line.h

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= libft.a

AR		= ar rcs

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all: 		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD

${NAME}:	${OBJS} ${HEAD} Makefile
				${AR} ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus
