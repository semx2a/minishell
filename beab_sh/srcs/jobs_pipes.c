/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:01:09 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 20:38:23 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	pipes(t_main *m)
{
	if (m->index == 0)
	{
		if (m->tokens->type == ID_STDIN_REDIR)
			ft_dup2(m->tokens->redir->fd, m->tokens->pipe[1]);
		else
			ft_dup2(0, o->fd_pipe[1]);
	}
	else if (m->index == m->cmd_nb - 1 && m->tokens->type == ID_STDOUT_REDIR)
		ft_dup2(m->tokens->pipe[2 * m->index - 2], m->tokens->redir->fd);
	else
		ft_dup2(m->tokens->pipe[2 * m->index - 2], m->tokens->pipe[2 * m->index + 1]);
}
