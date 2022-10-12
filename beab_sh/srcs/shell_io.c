/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:02:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 18:28:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_open(int *fd, char *pathname, int flags, int mode)
{
	*(fd) = open(pathname, flags, mode);
	if (*(fd) == -1)
		ft_error();
}

void	heredoc(t_main *m)
{
	char	*buf;

	(void)m;
	rl_on_new_line();
	rl_replace_line(buf, 0);
}
