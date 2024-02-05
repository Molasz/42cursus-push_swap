# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:46:01 by molasz            #+#    #+#              #
#    Updated: 2024/02/05 20:02:49 by molasz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_push_swap.c

HEAD	= ft_push_swap.h

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= push_swap.a

LIB		= libft

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD

lib:
				make -C ${LIB}
				cp ${LIB}/${LIB}.a ${NAME}

${NAME}:	lib ${OBJS} ${HEAD} Makefile
				${AR} ${NAME} ${OBJS}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus lib
