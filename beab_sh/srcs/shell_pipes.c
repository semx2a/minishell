/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:56:17 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 21:17:58 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	pipes(t_node *token)
{
	t_token	*data;

	data = (t_token *)token->data;
	if (data->is_redir)
	{
		if (data->id == O_STDIN_REDIR || data->id == O_DELEM)
			ft_dup2(data->fd, data->pipe[1]);
		else if (data->id == O_STDOUT_REDIR || data->id == O_APPEN)
			ft_dup2(data->pipe[1], data->fd);
	}
	else
		ft_dup2(data->pipe[0], ((t_token *)token->next->data)->pipe[1]);
}

/* t_operator	identify_pipe(t_main *m)
{
}
 */