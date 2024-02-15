# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:46:01 by molasz            #+#    #+#              #
#    Updated: 2024/02/15 19:46:33 by molasz-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= push_swap.c \
			algorithm.c \
			algorithm_utils.c \
			movements.c \
			push_num.c \
			push.c \
			reverse.c \
			rotate.c \
			sort.c \
			swap.c \
			utils.c

HEAD	= push_swap.h

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= push_swap

BSRCS	= checker_bonus.c \
			algorithm_utils.c \
			check_op_bonus.c \
			push.c \
			reverse.c \
			rotate.c \
			swap.c \
			utils.c \
			print.c

BHEAD	= checker_bonus.h

BOBJS	= ${BSRCS:.c=.o}

BDEPS	= ${BSRCS:.c=.d}

BNAME	= checker

LIB		= libft/libft.a

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c
				${CC} ${CFLAGS} -c $< -MMD

${NAME}:	${OBJS} ${HEAD} Makefile
				make -C libft
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

bonus:		${BNAME}

${BNAME}:	${BOBJS} ${BHEAD} Makefile
				make -C libft
				${CC} ${CFLAGS} ${BOBJS} ${LIB} -o ${BNAME}

clean:
				${RM} ${OBJS} ${DEPS}

fclean:		clean
				make fclean -C libft 
				${RM} ${NAME}

re:			fclean all

-include ${DEPS}

.PHONY:		clean fclean re all bonus
