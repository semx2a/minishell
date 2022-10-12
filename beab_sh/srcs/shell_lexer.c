/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 18:15:09 by seozcan          ###   ########.fr       */
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

void	inside_quotes(t_main *m, t_lexer *tmp)
{
	while (m->line[m->i] && !is_quote(m->line[m->i], m))
	{
		put_back(tmp, is_operator(m->line[m->i], m),
			ft_substr(m->line, (unsigned int)m->i, 1));
		m->i++;
	}
}

void	find_types(t_main *m, t_lexer *tmp)
{	
	m->i = 0;
	while (m->line[m->i] && ft_isascii(m->line[m->i]))
	{
		m->state = is_quote(m->line[m->i], m);
		put_back(tmp, is_operator(m->line[m->i], m),
			ft_substr(m->line, (unsigned int)m->i, 1));
		m->i++;
		if (m->line[m->i] && m->state == OPEN_QUOTE)
			inside_quotes(m, tmp);
	}
	if (m->state == OPEN_QUOTE)
		ft_putstr_fd("Error: Open quote found\n", 2);
}

void	build_token(t_main *m, t_lexer *a, t_lexer *b)
{
	m->i = 0;
	while (a->head)
	{
		while (a->head && a->head->type == O_SPACE)
			a->head = a->head->next;
		m->i = 0;
		m->type = a->head->type;
		m->j = (unsigned int)token_len(m, a->head);
		m->buf = xmalloc(sizeof(char) * (m->j + 1));
		m->buf[m->j] = '\0';
		while (a->head && m->type == a->head->type)
		{
			m->buf[m->i] = a->head->arg[0];
			a->head = a->head->next;
			m->i++;
		}
		new_lexer(m->type, ft_substr(m->buf, 0, m->i));
		free(m->buf);
	}
}

int	lexer(t_main *m)
{	
	t_lexer	*tmp_a;
	t_lexer	*tmp_b;

	m->state = DEFAULT;
	m->o.lexicon = xmalloc(sizeof(t_lexer));
	m->o.lexicon = NULL;
	tmp_a = m->o.lexicon;
	tmp_b = m->o.tokens;
	find_types(m, tmp_a);
	if (m->state == OPEN_QUOTE)
	{
		free(m->o.lexicon);
		return (0);
	}
	build_token(m, tmp_a, tmp_b);
	free_lexer(m->o.lexicon);
	return (1);
}
