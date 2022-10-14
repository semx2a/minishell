/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 23:43:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
		operators:
		- control operators: 		‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’,
									‘|&’, ‘(’, or ‘)’.
		- redirection operators :	< << > >> | &

		A token that doesn’t contain meta-character 
		and isn’t in quotes is a ‘word’. 
		
		A token that contains no quotes and at least
		one meta-character is an ‘operator’.
*/

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
	if ((!ft_isprint(c) || c == ' ') && m->state == S_DEFAULT)
		return (T_SPACE);
	if ((c == '$' && m->quote == DOUBLE_Q && m->state == S_OPEN_QUOTE)
		|| (ft_strchr("|&><$\"\'", c) && m->state == S_DEFAULT))
		return (T_OPERATOR);
	return (T_WORD);
}

t_lexer	*fill_lexer(t_main *m)
{
	t_lexer	*content;

	content = xmalloc(sizeof(t_lexer));
	content->type = is_operator(m->line[m->i], m);
	content->arg = m->line[m->i];
	return (content);
}

t_node	*find_types(t_main *m)
{	
	t_node	*lst;

	lst = NULL;
	m->i = 0;
	m->state = S_DEFAULT;
	while (m->line[m->i])
	{
		m->state = is_state(m->line[m->i], m);
		putback_node(&lst, new_node(fill_lexer(m)));
		m->i++;
	}
	return (lst);
}

int	lexer(t_main *m)
{	
	m->state = S_DEFAULT;
	m->lexicon = find_types(m);
	if (m->state == S_OPEN_QUOTE)
	{
		ft_putstr_fd("Error: Open quote found\n", 2);
		free_lexer(&m->lexicon);
		return (0);
	}
	return (1);
}
