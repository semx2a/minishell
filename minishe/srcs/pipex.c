/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/27 18:32:32 by seozcan          ###   ########.fr       */
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

void	pipex(t_main *m)
{
	m->o = (t_obj){0};
	m->o.fd_in = open(av[1], O_RDONLY);
	if (m->o.fd_in == -1)
		ft_error(ERR_INFILE);
	m->o.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (m->o.fd_out == -1)
		ft_error(ERR_OUTFILE);
	m->o.cmd_nb = m->defined_by_parsing;
	m->o.pipe_nb = m->define_by_parsing;
	m->o.paths = ft_split(m->env_path);
	ft_list_cmds(&m->o, ac, av);
	ft_assign_pipes(&m->o);
	m->o.index = -1;
	while (++m->o.index < m->o.cmd_nb)
		ft_process(&m->o, envp);
	ft_close_pipes(&m->o);
	ft_free_parent(&m->o);
	waitpid(-1, NULL, 0);
}
