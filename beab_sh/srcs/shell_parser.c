/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 20:29:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_operator	identify_operator(char *buf, char **operators)
{
	int	i;

	i = 0;
	while (operators[i])
	{
		if (!ft_strncmp(operators[i], buf, ft_strlen(buf)))
			return ((t_operator)i);
		i++;
	}
	return (O_WORD);
}

size_t	token_len(t_main *m, t_lexer *l)
{	
	t_lexer	*tmp;
	size_t	len;

	len = 0;
	tmp = l;
	while (tmp && m->type == tmp->type)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char	*fill_buf(t_main *m, t_lexer *a, t_types type)
{
	char	*buf;

	(void)type;
	buf = NULL;
	m->i = 0;
	m->j = (unsigned int)token_len(m, a);
	m->buf_a = xmalloc(sizeof(char) * (m->j + 1));
	m->buf_a[m->j] = '\0';
	while (a && m->type == a->type)
	{
		m->buf_a[m->i] = a->arg;
		a = a->next;
		m->i++;
	}
	return (buf);
}

void	fill_parser(t_main *m, t_parser *p)
{
	if (!p)
		p = new_node_parser(identify_operator(m->buf_b, m->operators),
				ft_substr(m->buf_a, 0, m->i));
	else
		p->next = new_node_parser(identify_operator(m->buf_b, m->operators),
				ft_substr(m->buf_a, 0, m->i));
}

t_parser	*build_tokens(t_main *m, t_lexer *a, t_parser *b)
{
	m->i = 0;
	while (a)
	{	
		m->type = a->type;
		while (a && a->type == T_SPACE)
			a = a->next;
		m->buf_a = fill_buf(m, a, T_WORD);
		m->buf_b = fill_buf(m, a, T_OPERATOR);
		fill_parser(m, b);
		free(m->buf_a);
		free(m->buf_b);
		a = a->next;
		if (b->next)
			b = b->next;
	}
	return (b);
}

int	parser(t_main *m)
{
	t_lexer		*tmp_a;
	t_parser	*tmp_b;

	tmp_a = m->lexicon;
	tmp_b = m->tokens;
	tmp_b = build_tokens(m, tmp_a, tmp_b);
	free_lexer(m->lexicon);
	return (1);
}
