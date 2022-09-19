/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/14 16:23:12 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_assign_pipes(t_obj *obj)
{
	int	i;

	i = 0;
	obj->fd_pipe = xmalloc(sizeof(int *) * (obj->pipe_nb * 2));
	while (i <= obj->cmd_nb - 1)
	{
		if (pipe(obj->fd_pipe + (2 * i)) == -1)
			ft_error(ERR_PIPE);
		i++;
	}
}

void	ft_list_cmds(t_obj *obj, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	obj->cmds = xmalloc(sizeof(char *) * (obj->cmd_nb + 1));
	while (++i < ac - 1)
	{
		obj->cmds[j] = ft_strdup(av[i]);
		j++;
	}
	obj->cmds[j] = 0;
}

void	pipex(t_main *m, int ac, char **av, char **envp)
{
	t_obj	obj;

	obj = (t_obj){0};
//	obj->fd_in = open(av[1], O_RDONLY);
//	if (obj->fd_in == -1)
//		ft_error(ERR_INFILE);
//	obj->fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
//	if (obj->fd_out == -1)
//		ft_error(ERR_OUTFILE);
//	obj->cmd_nb = ac - 3;
//	obj->pipe_nb = obj->cmd_nb - 1;
	obj.paths = m->paths;
	ft_list_cmds(&obj, ac, av);
	ft_assign_pipes(&obj);
	obj.index = -1;
	while (++obj.index < obj.cmd_nb)
		ft_process(&obj, envp);
	ft_close_pipes(&obj);
	ft_free_parent(&obj);
	waitpid(-1, NULL, 0);
}
