# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2021/12/14 18:14:37 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	:= libftprintf.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SDIR	:= srcs

SRCS	:= ft_printf.c ft_numbers.c ft_strings.c 

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::OBJS::

ODIR	:= objs

OBJS	= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

DEPS	= $(OBJS:.o=.d)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		:= gcc

WFLAGS	:= -MMD -Wall -Wextra -Werror

GFLAG	:= -Wconversion -g3

SANFLAG	:= -fsanitize=address

AR		:= ar

ARFLAGS	:= rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HEADERS::

IDIR	:= inc

INC		:= ft_printf.h

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIBFT	:= true

LDIR 	:= ../libft

LIB		:= libft.a

LINC	:= $(addprefix $(LDIR)/, $(IDIR)) 

LIBTF_PATH	:= $(addprefix $(LDIR)/, ${LIB})

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
GREEN		=	\033[0;92m
BGREEN		=	\033[1;92m
ORANGE  	=	\033[0;33m
NO_COLOR	=	\033[m
PURPLE		=	\033[0;35m
BPURPLE		=	\033[1;35m
BCYAN		=	\033[1;36m
ICYAN		=	\033[3;36

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARAMS::

INCLUDE_FLAGS 	=	$(addprefix -I , $(IDIR))

ifeq ($(IS_LIBFT),true)
	INCLUDE_FLAGS	+=	$(addprefix -I , $(LINC))
endif

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

vpath %.c $(SDIR)
vpath %.o $(ODIR)

all:			header message $(NAME)

$(ODIR)/%.o:	%.c
	@$(CC) $(WFLAGS) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(GREEN)ft_printf compilation:\t\t\t\t\t[OK]$(NO_COLOR)"

$(NAME):		$(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(LIBTF_PATH)
	@echo "$(GREEN)$(NAME):\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(OBJS):		| $(ODIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "$(GREEN)ft_printf objs folder:\t\t\t\t\t[OK]$(NO_COLOR)"

clean:
ifneq ($(wildcard ./$(ODIR)),)
	@rm -rf $(ODIR)
	@echo "$(ORANGE)ft_printf objs folder:\t\t\t\t\t[RM]$(NO_COLOR)"
else
	@rm -f $(wildcard %.o)
	@echo "$(ORANGE)ft_printf obj files:\t\t\t\t\t[RM]$(NO_COLOR)"
endif

fclean:		clean
	@rm -f $(NAME)
	@echo "$(ORANGE)$(NAME):\t\t\t\t\t\t[RM]$(NO_COLOR)"

header:
	@echo "\n$(BPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::\n$(NO_COLOR)"

message:
	@make -q $(NAME) && echo "$(BGREEN)All files are already up to date$(NO_COLOR)" || true

re:		fclean all

-include $(DEPS)

.PHONY:	all clean fclean re
