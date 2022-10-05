/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:34:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 17:28:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// might not need it in the end bc of free_parent();
// current issue it fixes:
// lexer camnot see if quote is closed
void	clean_main(t_main *m)
{
	m->i = 0;
	m->j = 0;
	m->err = 0;
	m->exit = 0;
	m->state = DEFAULT;
	m->quote = 0;
}

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
		clean_main(m);
	}
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
	 if (set_signals() == 1)
		return (1);
	shell_init(&m, envp);
	prompt(&m);
	ft_flush(&m);
	return (0);
}
