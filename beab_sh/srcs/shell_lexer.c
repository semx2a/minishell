/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 21:43:42 by seozcan          ###   ########.fr       */
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

t_types	is_operator(char c, t_main *m)
{	
	if ((!ft_isprint(c) || c == ' ') && m->state == S_DEFAULT)
		return (T_SPACE);
	if ((c == '$' && m->quote == DOUBLE_Q && m->state == S_OPEN_QUOTE)
		|| (ft_strchr("|&><$", c) && m->state == S_DEFAULT))
		return (T_OPERATOR);
	return (T_WORD);
}

t_states	is_quote(char c, t_main *m)
{
	if ((c == DOUBLE_Q || c == SINGLE_Q) && m->state != S_OPEN_QUOTE)
	{
		m->quote = c;
		return (S_OPEN_QUOTE);
	}
	if (c == m->quote && m->state == S_OPEN_QUOTE)
		return (S_CLOSING_QUOTE);
	return (S_DEFAULT);
}

void	inside_quotes(t_main *m, t_lexer *tmp)
{
	while (m->line[m->i] && is_quote(m->line[m->i], m) != 2)
	{
		tmp->next = new_node_lexer(is_operator(m->line[m->i], m),
				m->line[m->i]);
		m->i++;
	}
	m->state = is_quote(m->line[m->i], m);
	if (m->state == S_CLOSING_QUOTE)
		tmp->next = new_node_lexer(is_operator(m->line[m->i], m),
				m->line[m->i]);

}

t_lexer	*find_types(t_main *m)
{	
	t_lexer	*head;
	t_lexer	*tmp;

	m->i = 0;
	m->state = is_quote(m->line[m->i], m);
	head = new_node_lexer(is_operator(m->line[m->i], m), m->line[m->i]);
	tmp = head;
	m->i++;
	while (m->line[m->i] && ft_isascii(m->line[m->i]))
	{
		m->state = is_quote(m->line[m->i], m);
		if (m->state == S_OPEN_QUOTE)
			inside_quotes(m, tmp);
		else
			tmp->next = new_node_lexer(is_operator(m->line[m->i], m),
					m->line[m->i]);
		m->i++;
		tmp = tmp->next;
	}
	if (m->state == S_OPEN_QUOTE)
		ft_putstr_fd("Error: Open quote found\n", 2);
	return (head);
}

int	lexer(t_main *m)
{	
	m->state = S_DEFAULT;
	m->lexicon = find_types(m);
	if (m->state == S_OPEN_QUOTE)
	{
		free_lexer(m->lexicon);
		return (0);
	}
	return (1);
}
