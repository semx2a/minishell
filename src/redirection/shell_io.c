/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:16:27 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_fd(t_token *t)
{
	t_redir	*tmp;

	tmp = t->file;
	while (tmp)
	{
		if (tmp->type && tmp->type != DEFAULT && tmp->type != R_REDIR_IN)
			close(tmp->fd);
		tmp = tmp->next;
	}
}

int	ft_input(t_token *t, t_env *env)
{
	t_redir	*tmp;

	tmp = t->file;
	while (tmp)
	{
		if (tmp->type == REDIR_IN)
		{
			tmp->fd = open(tmp->file_path, O_RDONLY);
			if (tmp->fd == -1)
				return (ft_error_msg(1, tmp->file_path));
		}
		else if (tmp->type == R_REDIR_IN)
		{
			heredoc(t, tmp, env);
			if (g_status >= 128)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_output(t_token *t)
{
	t_redir	*tmp;

	tmp = t->file;
	while (tmp)
	{
		if (tmp->type == REDIR_OUT)
		{
			tmp->fd = open(tmp->file_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (tmp->fd == -1)
				return (ft_error_msg(1, tmp->file_path));
		}
		else if (tmp->type == R_REDIR_OUT)
		{
			tmp->fd = open(tmp->file_path, O_APPEND | O_CREAT | O_WRONLY, 0644);
			if (tmp->fd == -1)
			{
				g_status = 126;
				return (ft_error_msg(126, tmp->file_path));
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_redir(t_token *t, t_env *env)
{
	if (ft_input(t, env) == 1)
		return (1);
	if (ft_output(t) == 1)
		return (1);
	return (0);
}
