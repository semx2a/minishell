/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:53:49 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/21 18:23:00 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H

# define STRUCTURES_H

# include "minishell.h"

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
	char	*cmd;
	char	**cmds;
	char	**cmd_flags;
	char	*cmd_paths;
	char	**paths;
}	t_obj;

typedef struct s_main
{
	int		i;
	int		j;
	int		err;
	int		ret;
	char	c;
	char	*line;
	t_env	*env;
}	t_main;

#endif
