/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/06 19:41:38 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"
# include <stdbool.h>

typedef enum e_types
{
	WORD,
	OPERATOR,
}	t_types;

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
	int		cmd_ac;
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
	int		i;
	int		j;
	int		err;
	int		ret;
	int		exit;
	char	c;
	char	*line;
	char	*cwd;
	char	*prompt;
	t_env	*env;
	t_obj	o;
	t_stack	*args;
}	t_main;

#endif
