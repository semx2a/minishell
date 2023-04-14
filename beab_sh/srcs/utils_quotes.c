/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:08:45 by abonard           #+#    #+#             */
/*   Updated: 2022/12/17 06:21:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_loop_quotes(char *line, int i, int *b_quote)
{
	while (line[i])
	{
		if (line[i] == '"')
		{
			*b_quote = 1;
			return (-2);
		}
		else if (line[i] == '\'')
		{
			*b_quote = 2;
			return (-2);
		}
		if (!i)
			break ;
		i--;
	}
	return (i);
}

int	is_in_quotes(char *line, int i)
{
	int	b_quote;
	int	j;

	b_quote = 0;
	j = i;
	i = ft_loop_quotes(line, i, &b_quote);
	if (i == -1)
		return (0);
	i = j;
	while (line[i])
	{
		if (line[i] == '"' && b_quote == 1)
			return (1);
		else if (line[i] == '\'' && b_quote == 2)
			return (1);
		i++;
	}
	return (0);
}

void	check_quotes(char c, int *b_quote, int *quotes)
{
	if (c == '"' || c == '\'')
	{
		if (*b_quote == 0)
		{
			*quotes += 1;
			if (c == '"')
				*b_quote = 1;
			else
				*b_quote = 2;
		}
		else
		{
			if ((*b_quote == 1 && c == '"') || (*b_quote == 2 && c == '\''))
			{
				*quotes += 1;
				*b_quote = 0;
			}
		}
	}
}

int	check_quotes_is_valid(t_main *m, char *line)
{
	int		i;
	int		quotes;
	int		b_quote;

	if (!line)
		return (1);
	i = -1;
	quotes = 0;
	b_quote = 0;
	while (line[++i])
	{
		check_quotes(line[i], &b_quote, &quotes);
		if (line[i] == '\\' && b_quote == 0)
		{
			m->quotes_empty = true;
			return (0);
		}
	}
	if (quotes % 2 != 0)
	{
		ft_putstr_fd(ERR_QUOTE, STDERR_FILENO);
		m->quotes_empty = true;
		return (0);
	}
	return (1);
}

int	check_empty_quotes(t_main *m, char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] != '"' && tmp[i] != '\'' && tmp[i] != ' ')
			return (1);
		if (tmp[i] == '"' && tmp[i + 1] && tmp[i + 1] != '"')
			return (1);
		if (tmp[i] == '\'' && tmp[i + 1] && tmp[i + 1] != '\'')
			return (1);
	}
	m->quotes_empty = true;
	return (0);
}
