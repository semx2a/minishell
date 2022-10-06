/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/06 19:25:19 by seozcan          ###   ########.fr       */
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

void	inside_quotes(t_main *m, t_stack *tmp)
{
	while (m->line[m->i] && !is_quote(m->line[m->i], m))
	{
		put_back(tmp, is_operator(m->line[m->i], m),
			ft_substr(m->line, m->i, 1));
		m->i++;
	}
}

void	find_types(t_main *m, t_stack *tmp)
{	
	m->i = 0;
	while (m->line[m->i] && ft_isascii(m->line[m->i]))
	{
		m->state = is_quote(m->line[m->i], m);
		put_back(tmp, is_operator(m->line[m->i], m),
			ft_substr(m->line, m->i, 1));
		m->i++;
		if (m->line[m->i] && m->state == OPEN_QUOTE)
			inside_quotes(m, tmp);
	}
	if (m->state == OPEN_QUOTE)
		ft_putstr_fd("Error: Open quote found\n", 2);
}

void	build_token(t_main *m, t_stack *a, t_stack *b)
{
	unsigned int	status;
	unsigned int	start;
	size_t			len;
	char			*buff;

	m->i = 0;
	len = stack_size(a);
	buff = xmalloc(sizeof(char) * len + 1);
	buff[len] = '\0';
	while (a->head)
	{	
		start = m->i;
		m->i = 0;
		status = a->head->type;
		if (status != O_SPACE)
		{
			while (a->head && status == a->head->type)
			{
				buff[m->i] = a->head->arg[0];
				a->head = a->head->next;
				m->i++;
			}
			put_back(b, status, ft_substr(buff, start, m->i));
		}
		else
			a->head = a->head->next;
	}
	free(buff);
}

void	lexer(t_main *m)
{	
	t_stack	*tmp_a;
//	t_stack	*tmp_b;

	m->lexicon = xmalloc(sizeof(t_stack));
//	m->tokens = xmalloc(sizeof(t_stack));
	init_stack(m->lexicon);
//	init_stack(m->tokens);
	tmp_a = m->lexicon;
//	tmp_b = m->tokens;
	find_types(m, tmp_a);
//	build_token(m, tmp_a, tmp_b);
//	free_stack(m->lexicon);
}
