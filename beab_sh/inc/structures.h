/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 15:50:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"

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

typedef enum e_id
{
	CMD_ID,
	FLAG_ID,
	ARG_ID,
	INFILE_ID,
	OUTFILE_ID,
	PIPE_ID,
	OR_ID,
	AND_ID,
	STDIN_REDIR_ID,
	STDOUT_REDIR_ID,
	DELEM_ID,
	STDOUT_APPEND_ID,
	ENV_VAR_ID,
}	t_id;

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

typedef struct s_leaf
{
	int				item;
	size_t			h;
	size_t			d;
	struct s_leaf	*left;
	struct s_leaf	*right;
}	t_leaf;

typedef struct s_tree
{
	t_leaf	root;
	size_t	total_h;
}	t_tree;

typedef struct s_env
{
	char			*var;
	char			*cont;
	char			*total;
	int				stat_code;
	struct s_env	*next;
}	t_env;

typedef struct s_obj
{	
	pid_t			pid;
	size_t			index;
	size_t			pipe_nb;
	size_t			cmd_nb;
	int				cmd_ac;
	int				fd_in;
	int				fd_out;
	bool			is_infile;
	bool			is_outfile;
	int				*fd_pipe;
	char			*infile;
	char			*outfile;
	char			*bin_path;
	char			**cmds;
	char			**cmd_flags;
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
	t_obj			o;
	t_env			*env;
}	t_main;

#endif
