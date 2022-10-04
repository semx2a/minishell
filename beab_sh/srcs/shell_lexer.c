/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 21:31:00 by seozcan          ###   ########.fr       */
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

t_node	*assign_type(t_node *tmp, t_main *m)
{
	tmp->type = token_scan(m, m->line[m->i]);
	tmp->arg = ft_substr(m->line, m->i, 1);
	tmp = tmp->next;
	return (tmp);
}

t_node	*inside_quotes(t_main *m, t_node *tmp)
{
	while (m->line[m->i] && !is_quote(m->line[m->i], m))
	{
		tmp = assign_type(tmp, m);
		m->i++;
	}
	return (tmp);
}

void	line_scan(t_main *m)
{	
	t_node	*tmp;

	tmp = m->lexicon->head;
	while (m->line[m->i] && ft_isascii(m->line[m->i]))
	{
		m->state = is_quote(m->line[m->i], m);
		tmp = assign_type(tmp, m);
		m->i++;
		if (m->line[m->i] && m->state == OPEN_QUOTE)
			tmp = inside_quotes(m, tmp);
	}
	if (m->state == OPEN_QUOTE)
		ft_putstr_fd("Error: Open quote found\n", 2);
}

void	lexer(t_main *m)
{
	m->i = 0;
	m->lexicon = stack_alloc(&put_back, ft_strlen(m->line));
	line_scan(m);
}
