# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molasz <molasz-dev@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:46:01 by molasz            #+#    #+#              #
#    Updated: 2024/02/16 01:31:47 by molasz-a         ###   ########.fr        #
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

BOBJS	= ${BSRCS:.c=.o}

BDEPS	= ${BSRCS:.c=.d}

BNAME	= checker

LIB		= libft/libft.a

AR		= ar rcs

RM		 = rm -f

CC		 = cc

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:		%.c Makefile
				${CC} ${CFLAGS} -c $< -MMD

lib:
				make -C libft

${NAME}:	lib ${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

bonus:		${BNAME}

${BNAME}:	${BOBJS}
				make -C libft
				${CC} ${CFLAGS} ${BOBJS} ${LIB} -o ${BNAME}

clean:
				make clean -C libft
				${RM} ${OBJS} ${DEPS} ${BOBJS} ${BDEPS}

fclean:		clean
				make fclean -C libft 
				${RM} ${NAME} ${BNAME}

re:			fclean all

-include ${DEPS} ${BDEPS}

.PHONY:		clean fclean re all bonus lib
