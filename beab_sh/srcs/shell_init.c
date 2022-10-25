/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:38:15 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 19:13:08 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	shell_init(t_main *m, char **envp)
{
	m->env = put_env(envp);
	m->builtins = ft_split("env,exit,pwd,cd,echo,export,unset", ',');
	m->operators = ft_split("|,||,&&,<,>,<<,>>", ',');
}
