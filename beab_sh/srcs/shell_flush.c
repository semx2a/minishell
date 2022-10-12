/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_flush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 20:20:50 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_flush(t_main *m)
{
	free(m->line);
	free(m->prompt);
	free_env(m->env);
	free_parser(m->tokens);
	ft_free_stab(m->paths);
	ft_free_stab(m->builtins);
	ft_free_stab(m->operators);
	rl_clear_history();
}
