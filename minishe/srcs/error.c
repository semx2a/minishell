/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:32:13 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/21 18:33:09 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_error(const char *str)
{
	write(2, "ERR: ", 5);
	write(2, str, ft_strlen(str));
	if (ft_strnstr(strerror(errno), "Success", 7) == 0)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
