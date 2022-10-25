/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:54:07 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 20:44:41 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_builtin(t_token *data, char **builtins)
{
	int	i;

	i = 0;
	while (builtins[i])
	{
		if (ft_strcmp(builtins[i], data->av[0]) == 0)
			return (1);
		i++;
	}
	return (0);
}
