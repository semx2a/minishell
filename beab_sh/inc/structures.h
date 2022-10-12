/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 22:09:03 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LEXER::

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

typedef struct s_lexer
{	
	char			arg;
	enum e_types	type;
	struct s_node	*next;
	struct s_node	*prev;
}	t_lexer;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING::

typedef enum e_operator
{	
	ID_PIPE,
	ID_OR,
	ID_AND,
	ID_STDIN_REDIR,
	ID_STDOUT_REDIR,
	ID_DELEM,
	ID_APPEN,
	ID_ENV_VAR,
}	t_operator;

typedef struct s_redir
{
	int				pipe[2];
	int				fd;
	enum e_operator	id;
	char			*path;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef struct s_parser
{	
	char			**av;
	char			*bin_path;
	pid_t			pid;
	bool			is_piped;
	int				pipe[2];
	enum e_operator	id;
	struct s_redir	*redir;
	struct s_node	*next;
	struct s_node	*prev;
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
	size_t			index;
	enum e_states	state;
	enum e_types	type;
	int				cmd_ac;
	int				exit;
	char			quote;
	char			*line;
	char			*cwd;
	char			*prompt;
	char			*buf;
	char			**paths;
	char			**builtins;
	char			**operators;
	t_env			*env;
	t_lexer			*lexicon;
	t_parser		*tokens;
}	t_main;

#endif
