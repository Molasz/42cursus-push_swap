# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:46:01 by molasz            #+#    #+#              #
#    Updated: 2024/02/06 00:14:42 by molasz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c \
			swap.c \
			push.c \
			rotate.c \
			reverse.c 

HEAD	= push_swap.h

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= push_swap

LIB		= libft

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD

${NAME}:	lib ${OBJS} ${HEAD} Makefile
				make -C ${LIB}
				${CC} ${CFLAGS} ${OBJS} ${LIB}/${LIB}.a -o ${NAME}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				make fclean -C ${LIB}
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus lib
