/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:54:42 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_loop_redir(char *line, int i, int count)
{
	while (line[i])
	{
		if (count > 3)
			return (0);
		if (line[i] != ' ' && line[i] != '<' && line[i] != '>')
			return (1);
		if (line[i] == '>' || line[i] == '<')
			count++;
		if (i == 0)
			break ;
		i--;
	}
	return (i);
}

int	is_multiple_redir(char *line, int i)
{
	int	count;
	int	j;

	count = 0;
	j = i;
	i = ft_loop_redir(line, i, count);
	i = j;
	while (line[i])
	{
		if (count > 3)
			return (0);
		if (line[i] != ' ' && line[i] != '<' && line[i] != '>')
			return (1);
		if (line[i] == '>' || line[i] == '<')
			count++;
		i++;
	}
	if (count > 3)
		return (0);
	return (1);
}

int	ft_check_ends_redir(char *line, size_t len, bool err)
{
	if (line[len - 1] == '>' || line[len - 1] == '<')
	{
		if (err == true)
			ft_putstr_fd(ERR_NL, STDERR_FILENO);
		g_status = 2;
		return (0);
	}
	return (1);
}

int	ft_check_if_not_valid_redir(char *line, int i, bool err, size_t len)
{	
	if (!ft_check_ends_redir(line, len, err))
		return (0);
	while (line[++i])
	{
		if (line[i] == '>' || line[i] == '<')
		{
			if (!is_multiple_redir(line, i))
			{
				ft_putstr_fd(ERR_NL, STDERR_FILENO);
				return (0);
			}
			if (line[i + 1] == '>' || line[i + 1] == '<')
				i++;
			while (line[++i] == ' ')
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
