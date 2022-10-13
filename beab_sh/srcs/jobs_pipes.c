/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:01:09 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 18:43:42 by seozcan          ###   ########.fr       */
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
		if (m->tokens->id == O_STDIN_REDIR)
			ft_dup2(m->tokens->redir->fd, m->tokens->pipe[1]);
		else
			ft_dup2(0, m->tokens->pipe[1]);
	}
	else if (m->tokens->id == O_STDOUT_REDIR)
		ft_dup2(m->tokens->pipe[2 * m->index - 2], m->tokens->redir->fd);
	else
		ft_dup2(m->tokens->pipe[2 * m->index - 2],
			m->tokens->pipe[2 * m->index + 1]);
}
