/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:23:52 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/27 19:18:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_states	is_state(char c, t_main *m)
{	
	if (c == m->quote && m->state == S_OPEN_QUOTE)
		return (S_CLOSING_QUOTE);
	if (((c == DOUBLE_Q || c == SINGLE_Q) && m->state != S_OPEN_QUOTE)
		|| m->state == S_OPEN_QUOTE)
	{
		if ((c == DOUBLE_Q || c == SINGLE_Q) && m->state != S_OPEN_QUOTE)
			m->quote = c;
		return (S_OPEN_QUOTE);
	}
	return (S_DEFAULT);
}

t_types	is_operator(char c, t_main *m)
{	
	m->state = is_state(c, m);
	if ((!ft_isprint(c) || c == ' ') && m->state == S_DEFAULT)
		return (T_SPACE);
	if (/* (c == '$' && m->quote == DOUBLE_Q && m->state == S_OPEN_QUOTE)
		||  */(ft_strchr("|&><$\"\'", c) && m->state == S_DEFAULT))
		return (T_OPERATOR);
	return (T_WORD);
}

int	count_tokens(char *s, t_main *m)
{
	m->index = 0;
	m->i = 0;
	while (s[m->i])
	{	
		m->type = is_operator(s[m->i], m);
		while (s[m->i] && (is_operator(s[m->i], m) == m->type
				|| is_operator(s[m->i], m) == T_SPACE))
				m->i++;
		m->index++;
	}
	if (m->state == S_OPEN_QUOTE)
	{
		ft_putstr_fd("Error: Open quote found\n", 2);
		return (0);
	}
	m->stab = ft_calloc((m->index + 1), (sizeof(char *)));
	if (!m->stab)
		return (0);
	m->stab[m->index] = 0;
	return (1);
}

char	**create_tokens(char *s, t_main *m)
{
	if (!count_tokens(s, m))
		return (NULL);
	m->index = 0;
	m->i = 0;
	m->j = 0;
	while (s[m->i])
	{	
		m->type = is_operator(s[m->i], m);
		m->j = m->i;
		while (s[m->j] && (is_operator(s[m->j], m) == m->type
				|| is_operator(s[m->j], m) == T_SPACE))
				m->j++;
		m->stab[m->index] = ft_substr(s, (unsigned int)m->i, m->j - m->i);
		m->index++;
		m->i = m->j - 1;
		m->i++;
	}
	return (m->stab);
}
