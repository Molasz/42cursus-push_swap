# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:46:01 by molasz            #+#    #+#              #
#    Updated: 2024/02/08 15:22:31 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c \
		  	utils.c \
			sort.c \
			swap.c \
			push.c \
			rotate.c \
			reverse.c 

HEAD	= push_swap.h

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= push_swap

LIB		= libft/libft.a

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD -g

${LIB}:

${NAME}:	${OBJS} ${HEAD} Makefile
				make -C libft
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				make fclean -C libft 
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus
