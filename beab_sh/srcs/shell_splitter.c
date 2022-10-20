/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:23:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/20 19:05:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**allocate_stab(char *s)
{
	size_t		words;
	size_t		i;
	char		**ret;
	t_states	state;
	int			quote;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == quote && state == S_OPEN_QUOTE)
			state = S_DEFAULT;
		if ((s[i] == DOUBLE_Q || s[i] == SINGLE_Q) && state == S_DEFAULT)
		{
			state = S_OPEN_QUOTE;
			quote = s[i];
		}

		if (s[i] != SPACE && (s[i + 1] == '\0' || s[i + 1] == SPACE)
			&& state == S_DEFAULT)
			words++;
		i++;
	}
	ret = xmalloc(sizeof(char *) * (words + 1));
	ret[words] = 0;
	return (ret);
}

void	arg_splitter(t_parser *data, t_main *m, char *charset)
{	
	m->j = m->i;
	while (data->av[0][m->j] && !ft_strchr(charset, data->av[0][m->j]))
		m->j++;
	m->stab[m->index] = ft_substr(data->av[0], (unsigned int)m->i,
			m->j - m->i);
	m->index++;
	m->i = m->j - 1;
}

char	**fill_stab(t_parser *data, t_main *m)
{
	m->index = 0;
	m->i = 0;
	m->j = 0;
	m->stab = allocate_stab(data->av[0]);
	while (data->av[0][m->i])
	{
		if (data->av[0][m->i] != SPACE)
		{
			if (data->av[0][m->i] != DOUBLE_Q && data->av[0][m->j] != SINGLE_Q)
				arg_splitter(data, m, " ");
			else
				arg_splitter(data, m, "'\"");
			if (data->av[0][m->i + 1] == '\0')
				break ;
		}
		m->i++;
	}
	return (m->stab);
}
