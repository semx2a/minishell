/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:02:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 21:05:26 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	in_n_out(t_main *m)
{
	m->o.fd_in = open(m->o.infile, O_RDONLY);
	if (m->o.fd_in == -1)
		ft_error();
	m->o.fd_out = open(m->o.outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (m->o.fd_out == -1)
		ft_error();
}

void	heredoc(t_obj o)
{
	(void)o;
}
