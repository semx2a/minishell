/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 20:31:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_child(t_obj *obj)
{
	int	i;

	i = 0;
	while (obj->envtab[i] != 0)
	{
		free(obj->envtab[i]);
		i++;
	}
	free(obj->envtab);
	free(obj->bin_path);
}

void	ft_free_parent(t_obj *obj)
{
	int	i;

	i = 0;
//	close(obj->fd_in);
//	close(obj->fd_out);
	while (obj->paths[i] != 0)
	{
		free(obj->paths[i]);
		i++;
	}
	free(obj->paths);
	free_stack(obj->tokens);
	if (obj->pipe_nb > 0)
		free(obj->fd_pipe);
}

void	ft_close_pipes(t_obj *obj)
{
	size_t	i;

	i = 0;
	while (i < (obj->pipe_nb * 2))
	{
		close(obj->fd_pipe[i]);
		i++;
	}
}

void	ft_flush(t_main *m)
{
	ft_free_parent(&m->o);
	free(m->line);
	free(m->cwd);
	free_env(m->env);
	ft_free_stab(m->builtins);
	ft_free_stab(m->operators);
	ft_free_stab(m->operands);
	rl_clear_history();
}
