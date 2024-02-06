ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	libft.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC		=	$Sft_allocate_tab.c \
			$Sft_atoi.c \
			$Sft_atoi_hexa.c \
			$Sft_atoli.c \
			$Sft_bzero.c \
			$Sft_calloc.c \
			$Sft_error.c \
			$Sft_free_stab.c \
			$Sft_free_tab.c \
			$Sft_gnl.c \
			$Sft_isalnum.c \
			$Sft_isalpha.c \
			$Sft_isascii.c \
			$Sft_isdigit.c \
			$Sft_isprint.c \
			$Sft_itoa.c \
			$Sft_lstadd_back.c \
			$Sft_lstadd_front.c \
			$Sft_lstclear.c \
			$Sft_lstdelone.c \
			$Sft_lstiter.c \
			$Sft_lstlast.c \
			$Sft_lstmap.c \
			$Sft_lstnew.c \
			$Sft_lstsize.c \
			$Sft_memchr.c \
			$Sft_memcmp.c \
			$Sft_memcpy.c \
			$Sft_memmove.c \
			$Sft_memset.c \
			$Sft_multi_split.c \
			$Sft_node_addback.c \
			$Sft_node_addfront.c \
			$Sft_nodeclear.c \
			$Sft_node_delone.c \
			$Sft_node_iter.c \
			$Sft_node_last.c \
			$Sft_nodemap.c \
			$Sft_nodenew.c \
			$Sft_node_size.c \
			$Sft_print_stab.c \
			$Sft_putchar_fd.c \
			$Sft_putendl_fd.c \
			$Sft_putnbr_fd.c \
			$Sft_putstr_fd.c \
			$Sft_split.c \
			$Sft_double_list_free.c \
			$Sft_double_list_init.c \
			$Sft_double_list_push.c \
			$Sft_double_list_putback.c \
			$Sft_double_list_putfront.c \
			$Sft_double_list_reverse.c \
			$Sft_double_list_rotate.c \
			$Sft_double_list_size.c \
			$Sft_double_list_swap.c \
			$Sft_strchr.c \
			$Sft_strcmp.c \
			$Sft_strcpy.c \
			$Sft_strdup.c \
			$Sft_strisdigit.c \
			$Sft_striteri.c \
			$Sft_strjoin_free.c \
			$Sft_strjoin.c \
			$Sft_strlcat.c \
			$Sft_strlcpy.c \
			$Sft_strlen.c \
			$Sft_strmapi.c \
			$Sft_strncmp.c \
			$Sft_strnstr.c \
			$Sft_strrchr.c \
			$Sft_strtrim.c \
			$Sft_substr.c \
			$Sft_tablen.c \
			$Sft_tolower.c \
			$Sft_toupper.c \
			$Sft_xmalloc.c

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

endif