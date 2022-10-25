/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/25 20:37:23 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_exit(t_token *data, bool is_forked)
{
	int		ret;
	size_t	cmd_ac;

	ret = 0;
	cmd_ac = ft_tablen(data->av);
	if (data->av && cmd_ac > 2 && is_forked)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	else if (data->av && cmd_ac >= 2)
	{
		if (ft_strisdigit(data->av[1]) == 1)
			ret = ft_atoi(data->av[1]);
		else
		{
			if (is_forked)
				ft_putstr_fd("exit: numeric argument required\n", 2);
			return (1);
		}
	}
	if (is_forked)
		printf("exit\n");
	exit(ret);
	return (ret);
}
