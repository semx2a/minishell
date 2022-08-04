# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 15:38:04 by abonard           #+#    #+#              #
#    Updated: 2022/08/04 18:38:40 by abonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/test.c \

INCLUDES	=	./includes/libft.h \
				./includes/ft_printf.h \
				./includes/minishell.h \

HEAD		= ./includes/

LIBFT		= ./libft/libft.a

LIB_DIR		= ./libft/

NAME		= minishell

CC			= clang

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -lreadline


.c.o:
		@${CC} ${CFLAGS} -I${HEAD_BONUS} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR} 2> /dev/null
			@echo "${GREEN}\nlibft.a		has been created${NC}"
			@${CC} ${CFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT}
			@echo "minishell		has been created\n${NC}"


bonus:		${NAME3} ${NAME4}

clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS}
			@${RM} ${OBJS2}
			@${RM} ${OBJS3}
			@${RM} ${OBJS4}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME} 
			@echo "${GREEN}[ OK ]${RED}everything	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re

