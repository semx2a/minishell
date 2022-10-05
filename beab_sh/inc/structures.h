/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 19:51:43 by seozcan          ###   ########.fr       */
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

typedef struct s_obj
{
	int		fd_in;
	int		fd_out;
	int		pipe_nb;
	int		cmd_nb;
	int		*fd_pipe;
	int		index;
	pid_t	pid;
	char	*infile;
	char	*outfile;
	char	*cmd;
	char	**cmds;
	char	**cmd_flags;
	char	*cmd_paths;
	char	**paths;
	char	*path;
}	t_obj;

typedef struct s_main
{
	unsigned int	i;
	unsigned int	j;
	int				err;
	int				ret;
	int				exit;
	int				state;
	char			quote;
	char			c;
	char			*line;
	char			*cwd;
	char			*prompt;
	t_env			*env;
	t_obj			o;
	t_stack			*lexicon;
}	t_main;

#endif
