/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:15:54 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *bin_name, char *err_msg)
{
	if (err_msg)
	{	
		ft_putstr_fd(bin_name, STDERR_FILENO);
		if (ft_strnstr(strerror(errno), "Success", 7) == 0)
			perror(err_msg);
		else
		{
			ft_putstr_fd(err_msg, 2);
			write(2, "\n", 1);
		}
	}
	else
		perror(bin_name);
	if (!errno)
		return (EXIT_FAILURE);
	return (errno);
}
