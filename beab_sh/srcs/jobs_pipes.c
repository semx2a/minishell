/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:01:09 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/17 19:59:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	pipes(t_parser *curr, t_parser *next, t_main *m)
{
	t_redir	*r;

	r = NULL;
	if (p->redir)
	{
		r = (t_redir *)curr->redir->data;
		if (r->id == O_STDIN_REDIR || r->id == O_DELEM)
			ft_dup2(r->fd, curr->pipe[1]);
		else if (r->id == O_STDOUT_REDIR || curr->id == O_APPEN)
			ft_dup2(p->pipe[1], r->fd);
	}
	else
		ft_dup2(curr->pipe[0], next->pipe[1]);
}
