ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	minishell

UNAME	=	$(shell uname)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC		=	$(addprefix $Sbuiltins/, \
				shell_builtins.c \
				shell_cd.c \
				shell_echo.c) \
			$(addprefix $Senv/, \
				shell_env.c \
				shell_export.c \
				shell_lvl.c \
				shell_unset.c \
				utils_env.c \
				utils_export.c) \
			$(addprefix $Sexecution/, \
				shell_jobs.c \
				shell_pipes.c) \
			$(addprefix $Sexpansion/, \
				shell_expansion.c) \
			$(addprefix $Sparsing/, \
				shell_lexer.c \
				shell_parsing.c \
				shell_parsing_utils.c \
				utils_quotes.c) \
			$(addprefix $Sredirection/, \
				shell_heredoc.c \
				shell_io.c \
				shell_path.c \
				shell_redir.c \
				utils_redir_op.c) \
			$(addprefix $Ssignals/, \
				shell_sig_set.c \
				shell_signals.c \
				shell_signals_heredoc.c) \
			$(addprefix $Sutils/, \
				shell_err_msg.c \
				shell_exit.c \
				shell_flush.c \
				shell_init.c \
				shell_structs.c \
				utils.c ) \
			$Smain.c

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	gcc

ifeq ($(UNAME), Darwin)
	CC = clang
endif

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIB	= 	true

LIB		= 	$Llibft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PTF	= 	false

PTF		= 	$Plibftprintf.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MLX	= 	false

MLX		= 	$Mlibmlx_$(UNAME).a

endif