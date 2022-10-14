/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 23:51:00 by seozcan          ###   ########.fr       */
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
	return (NULL);
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

char	**build_token(t_main *m)
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

t_redir	*fill_redir(t_main *m)
{
	t_redir	*content;

	content = xmalloc(sizeof(t_parser));
	content->type = is_operator(m->line[m->i], m);
	content->arg = m->line[m->i];
	return (content);
}

t_parser	*fill_parser(t_main *m)
{
	t_parser	*content;

	content = xmalloc(sizeof(t_parser));
	content->id = is_operator(m->line[m->i], m);
	if (content->id == ID_PIPE)
	{
		content->is_piped = 1;
		pipe(content->pipe);
	}
	else if (content->id )
	content->av = build_token(m);
	return (content);
}

int	parser(t_main *m)
{	
	t_node	*ret;

	m->i = 0;
	while (m->lexicon)
	{	
		putback_node(&m->tokens, new_node(fill_parser(m)));
		m->lexicon = m->lexicon->next;
	}
	free_lexer(&m->lexicon);
	return (1);
}
