/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:23:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/18 19:57:53 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**allocate_stab(char *s)
{
	size_t	words;
	size_t	i;
	char	**ret;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != SPACE && (s[i + 1] == '\0' || s[i + 1] == SPACE))
			words++;
		i++;
	}
	ret = xmalloc(sizeof(char *) * (words + 1));
	ret[j] = 0;
	return (ret);
}

char	*arg_splitter(t_parser *data, t_main *m, char *charset)
{
	m->j = m->i;
	while (!ft_strchr(charset, data->av[0][m->j]))
		m->j++;
	new[tab++] = ft_substr(data->av[0], m->i, m->j - m->i);
	free(m->buf);
	m->i = m->j - 1;
}

char	**fill_stab(t_parser *data, t_main *m)
{
	char	**new;
	size_t	tab;

	m->i = 0;
	tab = 0;
	new = allocate_stab(data->av[0]);
	while (data->av[0][m->i])
	{
		if (data->av[0][m->i] != DOUBLE_Q || data->av[0][m->j] != SINGLE_Q)
			arg_splitter(data, m, " ");
		else
			arg_splitter(data, m, "'\"");
		if (data->av[0][i + 1] == '\0')
			break ;
		m->i++;
	}
	return (new);
}
