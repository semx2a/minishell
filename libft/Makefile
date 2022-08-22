# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2022/08/22 18:03:58 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	:= libft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SDIR	:= srcs

SRCS	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
ft_tablen.c ft_atoli.c ft_free_tab.c ft_allocate_tab.c\
ft_free_stab.c ft_atoi_hexa.c

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::OBJECTS::

ODIR	:= objs

OBJS	=  $(addprefix $(ODIR)/, $(SRCS:.c=.o))

DEPS	= $(OBJS:.o=.d)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		:= clang

WFLAGS	:= -MMD -Wall -Wextra -Werror 

WCONV 	:= -Wconversion

GFLAG	:=  -g3

SANFLAG	:= -fsanitize=address

AR		:= ar

ARFLAGS	:= rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HEADERS::

IDIR	:= inc

INC		:= libft.h

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

BLUE		:=	\033[1;34m
CYAN		:=	\033[0;36m
GREEN		:=	\033[0;92m
BGREEN		:=	\033[1;92m
ORANGE  	:=	\033[0;33m
NO_COLOR	:=	\033[m
PURPLE		:=	\033[0;35m
BPURPLE		:=	\033[1;35m
BCYAN		:=	\033[1;36m
ICYAN		:=	\033[3;36m

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

vpath %.c $(SDIR)
vpath %.o $(ODIR)

all:			header message $(NAME)

$(ODIR)/%.o:	%.c
	@$(CC) $(WFLAGS) -I $(IDIR) -c $< -o $@
	@echo "$(GREEN)libft compilation:\t\t\t\t\t[OK]$(NO_COLOR)"

$(NAME):		$(OBJS)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME):\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(OBJS):		| $(ODIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "$(GREEN)libft objs folder:\t\t\t\t\t[OK]$(NO_COLOR)"

clean:
ifneq ($(wildcard ./$(ODIR)),)
	@rm -rf $(ODIR)
	@echo "$(ORANGE)libft objs folder:\t\t\t\t\t[RM]$(NO_COLOR)"
else
	@rm -f $(wildcard %.o)
	@echo "$(ORANGE)libft obj files:\t\t\t\t\t[RM]$(NO_COLOR)"
endif

fclean:		clean
	@rm -f $(NAME)
	@echo "$(ORANGE)$(NAME):\t\t\t\t\t\t[RM]$(NO_COLOR)"

header:
	@echo "\n$(BPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::::::LIBFT::\n$(NO_COLOR)"

message:
	@make -q $(NAME) && echo "$(BGREEN)All files are already up to date\n$(NO_COLOR)" || true

re:		fclean all

-include $(DEPS)

.PHONY:	all clean fclean re