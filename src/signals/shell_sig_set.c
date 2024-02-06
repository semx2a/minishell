/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_sig_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:00:43 by ringii            #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_signals(void)
{
	if (!(signal(SIGINT, ft_cntlc)))
		return (0);
	return (1);
}

int	set_sig(void)
{
	if (!signal(SIGQUIT, ft_cntl_slsh))
		return (0);
	return (1);
}
