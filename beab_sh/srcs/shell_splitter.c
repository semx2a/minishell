/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_splitter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:32:10 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/27 19:29:37 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**count_args(char *s, t_main *m)
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

void	arg_splitter(char *s, char c, t_main *m)
{	
	m->k = m->j;
	while (s[m->k] && s[m->k] != c)
		m->k++;
	m->stab[m->index] = ft_substr(s, (unsigned int)m->j,
			m->k - m->j);
	m->index++;
	m->j = m->k - 1;
}

char	**shell_splitter(char *s, t_main *m)
{
	m->index = 0;
	m->j = 0;
	m->k = 0;
	m->stab = count_args(s, m);
	while (s[m->j])
	{	
		m->state = is_state(s[m->j], m);
		if (s[m->j] != SPACE)
		{	
			if (m->state == S_DEFAULT)
				arg_splitter(s, SPACE, m);
			else if (m->state == S_OPEN_QUOTE && s[m->j] != m->quote)
				arg_splitter(s, m->quote, m);
			if (s[m->j + 1] == '\0')
				break ;
		}
		m->j++;
	}
	return (m->stab);
}
