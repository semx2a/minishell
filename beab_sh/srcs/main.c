/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:34:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/29 21:43:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_prompt(t_main *m, char **envp)
{
	while (1)
	{
		m->cwd = getcwd(m->cwd, 4062);
		m->cwd = ft_strjoin(m->cwd, "$");
		m->line = readline(m->cwd);
		add_history(m->line);
//		lexer(m);
//		print_list(m->args);
//		parser();
		ft_job(m, envp);
		ft_free_parent(&m->o);
		waitpid(-1, NULL, 0);
		free(m->line);
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{	
	t_main	m;

	(void)av;
	if (ac != 1)
		ft_error();
	if (*envp == NULL)
		ft_error();
	m = (t_main){0};
	// if (ft_set_signals() == 1)
	//   return (1);
	m.env = ft_put_env(envp);
	shell_init(&m);
	ft_prompt(&m, envp);
	return (0);
}
