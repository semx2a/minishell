# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 19:48:37 by abonard           #+#    #+#              #
#    Updated: 2022/08/22 19:11:26 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

NC		=	\033[0m
RED		=	\033[0;91m
ORANGE	=	\033[93m
GREEN	=	\033[0;92m
PURPLE	=	\033[0;95m
BLUE	=	\033[0;34m
BOLD	=	\033[1m

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SRCS_SERVER		=	src/server.c

SRCS_CLIENT		=	src/client.c

SRCS_SERVER_B	=	bonus/server_bonus.c

SRCS_CLIENT_B	=	bonus/client_bonus.c

OBJS			= 	${SRCS_SERVER:.c=.o}

OBJS2			= 	${SRCS_CLIENT:.c=.o}

OBJS3			= 	${SRCS_SERVER_B:.c=.o}

OBJS4			= 	${SRCS_CLIENT_B:.c=.o}

IDIR			=	inc

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIBFT		:=	true

LDIR 			:=	../libft

LIB				:=	$(addprefix $(LDIR)/, libft.a)

LIBTF_PATH		=	$(addprefix $(LDIR)/, ${LIB})

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME			= 	server

NAME2			= 	client

NAME3			= 	server_bonus

NAME4			= 	client_bonus

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC				=	clang

RM				= 	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g3

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARAMS::

INCLUDE_FLAGS		=	$(addprefix -I , $(INC))

ifeq ($(IS_LIBFT),true)
	INCLUDE_FLAGS	+=	$(addprefix -I , $(LINC))
endif

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE_FLAGS) -c $< -o ${<:.c=.o}
	@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"

all:		${NAME} ${NAME2}

${NAME}:	${OBJS}
	@make -C ${LDIR}
	@echo "${GREEN}\nlibft.a		has been created${NC}"
	@${CC} ${CFLAGS} $(INCLUDE_FLAGS) $(OBJS) ${LIB} -o ${NAME} 
	@echo "server		has been created\n ${NC}"

${NAME2}:	${OBJS2}
	@${CC} ${CFLAGS} $(INCLUDE_FLAGS) $(OBJS2) ${LIB} -o ${NAME2}
	@echo "${GREEN}client		has been created\n${NC}"

${NAME3}:	${OBJS3}
	@make -C ${LDIR}
	@echo "${GREEN}\nlibft.a		has been created"
	@${CC} ${CFLAGS} $(INCLUDE_FLAGS) $(OBJS3) ${LIB} -o ${NAME3} 
	@echo "server_bonus		has been created\n${NC}"


${NAME4}:	${OBJS4}
	@echo "${GREEN}\nlibft.a		has been created"
	@${CC} ${CFLAGS} $(INCLUDE_FLAGS) $(OBJS4) ${LIB} -o ${NAME4} 
	@echo "client_bonus		has been created\n${NC}"

bonus:		${NAME3} ${NAME4}

clean:
	@make -C $(LDIR) clean
	@${RM} ${OBJS}
	@${RM} ${OBJS2}
	@${RM} ${OBJS3}
	@${RM} ${OBJS4}
	@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
	@make -C $(LDIR) fclean
	@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
	@${RM} ${NAME} ${NAME2} ${NAME3} ${NAME4}
	@echo "${GREEN}[ OK ]${RED}everything	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re
