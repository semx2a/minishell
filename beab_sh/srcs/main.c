/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wac <wac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:34:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/28 00:24:15 by wac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	prompt(t_main *m)
{
	while (!m->exit)
	{
		m->cwd = getcwd(m->cwd, 4096);
		m->prompt = ft_strjoin(m->cwd, "$ ");
		m->line = readline(m->prompt);
		job(m);
		add_history(m->line);
		free(m->line);
		free(m->prompt);
	}
}

int	main(int ac, char **av, char **envp)
{	
	t_main	*m;

	(void)av;
	if (ac != 1)
		ft_error();
	//if (*envp == NULL)
		//ft_error();
	m = (t_main *)ft_calloc(1, sizeof(t_main));
	if (set_signals() == 1)
		return (1);
	shell_init(m, envp);
	prompt(m);
	ft_flush(m);
	return (0);
}
