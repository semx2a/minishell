/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:20:56 by abonard           #+#    #+#             */
/*   Updated: 2022/08/17 18:52:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_main	m;

	m = (t_main){0};
	(void)argc;
	(void)argv;
	(void)envp;
	(void)m;
	while(1)
		//aficher un prompt jusqu'a la nouvelle commande
		get_next_line(1);
		/*if (ft_strcmp(argv[i], "echo"))
			printf("%s\n", argv[i + 1]);
		if (ft_strcmp(argv[i], "pwd"))
			//PATH
		if (ft_strcmp(argv[i], "env"))
			//get_env();
		if (ft_strcmp(argv[i], "export"))
			//export?
		if (ft_strcmp(argv[i], "unset"))
			//what the fuck is that
		if (ft_strcmp(argv[i], "cd"))
			//chdir, google it
		if (ft_strcmp(argv[i], "exit"))
		//quit the program?*/
}
