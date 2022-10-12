/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 18:53:26 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LEXER ENUMS::

typedef enum e_types
{
	WORD,
	OPERATOR,
	O_SPACE,
}	t_types;

typedef enum e_states
{
	DEFAULT,
	OPEN_QUOTE,
	CLOSE_QUOTE,
}	t_states;

typedef enum e_parser
{
	DOUBLE_Q = 34,
	AMPERSAND = 38,
	SINGLE_Q = 39,
	LEFT_A = 60,
	RIGHT_A = 62,
	PIPE = 124,
}	t_parser;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING IDs::

typedef enum e_operand
{
	CMD_ID,
	FLAG_ID,
	ARG_ID,
	INFILE_ID,
	OUTFILE_ID,
}	t_operand;

typedef enum e_operator
{	
	PIPE_ID,
	OR_ID,
	AND_ID,
	STDIN_REDIR_ID,
	STDOUT_REDIR_ID,
	DELEM_ID,
	STDOUT_APPEND_ID,
	ENV_VAR_ID,
}	t_operator;

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LINKED LISTS::

typedef struct s_node
{
	int				type;
	char			*arg;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_env
{
	char			*var;
	char			*cont;
	char			*total;
	int				stat_code;
	struct s_env	*next;
}	t_env;

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::STRUCTURES::

typedef struct s_obj
{	
	pid_t			pid;
	size_t			index;
	size_t			pipe_nb;
	size_t			cmd_nb;
	int				cmd_ac;
	int				fd_in;
	int				fd_out;
	int				*fd_pipe;
	char			*infile;
	char			*outfile;
	char			*bin_path;
	char			**paths;
	char			**envtab;
	t_stack			*lexicon;
	t_stack			*tokens;
}	t_obj;

typedef struct s_main
{
	size_t			i;
	size_t			j;
	int				type;
	int				err;
	int				ret;
	int				exit;
	int				state;
	char			quote;
	char			c;
	char			*line;
	char			*cwd;
	char			*prompt;
	char			*buff;
	char			**builtins;
	char			**operators;
	char			**operands;
	t_obj			o;
	t_env			*env;
}	t_main;

#endif
