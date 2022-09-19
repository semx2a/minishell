/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:20:56 by abonard           #+#    #+#             */
/*   Updated: 2022/09/14 16:23:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_paths(char **envp)
{
	while (*envp != 0)
	{
		if (ft_strnstr(*envp, "PATH", 5))
			return (*envp + 5);
		envp++;
	}
	ft_error(ERR_PATH);
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_main	m;

	m = (t_main){0};
	if (ac != 1)
		ft_error(ERR_ARGS);
	if (*envp == NULL)
		ft_error(ERR_ENV);
	m.str = ft_paths(envp);
	m.paths = ft_split(m.str, ':');
	// lexing
	// parsing
	while (1)
		get_next_line(1);
	pipex(&m, ac, av, envp);
	return (0);
}
