/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_set_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:10:55 by abonard           #+#    #+#             */
/*   Updated: 2022/10/28 17:11:15 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_cntlc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_cntl_slsh(int sig)
{
	(void)sig;
	write(1, "\b\b  \b\b", 6);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_sig_ghost(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		ft_putstr_fd("\n", 1);
}