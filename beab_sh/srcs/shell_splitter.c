/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:23:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/21 16:21:00 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**allocate_stab(char *s, t_main *m)
{
	size_t		words;
	size_t		i;
	char		**ret;

	words = 0;
	i = 0;
	while (s[i])
	{
		m->state = is_state(s[i], m);
		if (s[i] != SPACE && (s[i + 1] == '\0' || s[i + 1] == SPACE)
			&& m->state != S_OPEN_QUOTE)
			words++;
		i++;
	}
	ret = xmalloc(sizeof(char *) * (words + 1));
	ret[words] = 0;
	return (ret);
}

void	arg_splitter(char *s, char *charset, t_main *m)
{	
	m->k = m->j;
	while (s[m->k] && !ft_strchr(charset, s[m->k]))
		m->k++;
	m->stab[m->index] = ft_substr(s, (unsigned int)m->j,
			m->k - m->j);
	m->index++;
	m->j = m->k - 1;
}

char	**fill_stab(char *s, t_main *m)
{
	m->index = 0;
	m->j = 0;
	m->k = 0;
	m->stab = allocate_stab(s, m);
	while (s[m->j])
	{	
		m->state = is_state(s[m->j], m);
		if (s[m->j] != SPACE)
		{	
			if (m->state == S_DEFAULT)
				arg_splitter(s, " ", m);
			else if (m->state == S_OPEN_QUOTE && (s[m->j] != DOUBLE_Q
					&& s[m->j] != SINGLE_Q))
				arg_splitter(s, "'\"", m);
			if (s[m->j + 1] == '\0')
				break ;
		}
		m->j++;
	}
	return (m->stab);
}
