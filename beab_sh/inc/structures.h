/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 23:57:06 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LEXER::

typedef enum e_types
{
	T_WORD,
	T_OPERATOR,
	T_SPACE,
}	t_types;

typedef enum e_states
{
	S_DEFAULT,
	S_OPEN_QUOTE,
	S_CLOSING_QUOTE,
}	t_states;

typedef struct s_lexer
{	
	char			arg;
	enum e_types	type;
}	t_lexer;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING::

typedef enum e_operator
{
// pipes
	O_PIPE,
	O_OR,
	O_AND,
// redirs
	O_STDIN_REDIR,
	O_STDOUT_REDIR,
	O_DELEM,
	O_APPEN,
//env
	O_ENV_VAR,
}	t_operator;

typedef struct s_redir
{
	int				pipe[2];
	int				fd;
	enum e_operator	id;
	char			*path;
}	t_redir;

typedef struct s_parser
{	
	char			**av;
	char			*bin_path;
	pid_t			pid;
	bool			is_piped;
	int				pipe[2];
	enum e_operator	id;
	t_node			*redir;
}	t_parser;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::ENVIRONMENT::

typedef struct s_env
{
	char			*var;
	char			*cont;
	char			*total;
	int				stat_code;
	struct s_env	*next;
}	t_env;

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MAIN::

typedef struct s_main
{
	size_t			i;
	size_t			j;
	size_t			k;
	size_t			index;
	size_t			cmd_nb;
	size_t			pipe_nb;
	enum e_states	state;
	enum e_types	type;
	int				cmd_ac;
	int				exit;
	char			quote;
	char			*line;
	char			*cwd;
	char			*prompt;
	char			*buf_a;
	char			*buf_b;
	char			**paths;
	char			**builtins;
	char			**operators;
	t_env			*env;
	t_node			*lexicon;
	t_node			*tokens;
}	t_main;

#endif
