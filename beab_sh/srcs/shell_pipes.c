/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:56:17 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/22 15:49:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	pipes(t_node *token, t_main *m)
{
	t_redir		*r;
	t_token	*p;

	r = NULL;
	p = (t_token *)token->data;
	if (p->redir)
	{
		r = (t_redir *)p->redir->data;
		if (r->id == (O_STDIN_REDIR || O_DELEM))
			ft_dup2(r->fd, p->pipe[1]);
		else if (r->id == (O_STDOUT_REDIR || O_APPEN))
			ft_dup2(p->pipe[1], r->fd);
	}
	else
		ft_dup2(p->pipe[0], ((t_token *)token->next->data)->pipe[1]);
}



t_operator	identify_pipe(t_main *m)
{
}
