/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:27:20 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_if_not_valid_pipes(char *line, int i, bool err, size_t len)
{
	if (line[0] == '|' || line[len - 1] == '|')
	{
		if (err == true)
			ft_putstr_fd(ERR_PIPE, STDERR_FILENO);
		g_status = 2;
		return (0);
	}
	while (line[++i])
	{
		if (line[i] == '|')
		{
			if (is_in_quotes(line, i) == 1)
				continue ;
			while (line[++i] && line[i] == ' ')
				;
			if (line[i] == '|')
			{
				if (err == true)
					ft_putstr_fd(ERR_PIPE, STDERR_FILENO);
				g_status = 2;
				return (0);
			}
		}
	}
	return (1);
}

char	*lexer(t_main *m)
{
	char	*tmp;
	size_t	len;

	m->p = init_parser();
	m->quotes_empty = false;
	tmp = NULL;
	tmp = ft_strtrim(m->line, " \f\t\n\r\v");
	if (!tmp)
		return (NULL);
	len = ft_strlen(tmp);
	if (!len)
	{
		m->quotes_empty = true;
		free(tmp);
		return (NULL);
	}
	if (!ft_check_if_not_valid_pipes(tmp, -1, true, len)
		|| !ft_check_if_not_valid_redir(tmp, -1, true, len)
		|| !check_quotes_is_valid(m, tmp) || !check_empty_quotes(m, tmp))
	{
		m->quotes_empty = true;
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
