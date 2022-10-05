/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:01:09 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/01 20:45:48 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_assign_pipes(t_obj *o)
{		
	int	i;

	i = 0;
	o->fd_pipe = malloc(sizeof(int *) * (size_t)(o->pipe_nb * 2));
	if (!o->fd_pipe)
		ft_error();
	while (i <= o->cmd_nb - 1)
	{
		if (pipe(o->fd_pipe + (2 * i)) == -1)
			ft_error();
		i++;
	}
}

static void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	pipes(t_obj *o)
{
	if (o->index == 0)
		ft_dup2(o->fd_in, o->fd_pipe[1]);
	else if (o->index == o->cmd_nb - 1)
		ft_dup2(o->fd_pipe[2 * o->index - 2], o->fd_out);
	else
		ft_dup2(o->fd_pipe[2 * o->index - 2], o->fd_pipe[2 * o->index + 1]);
}
