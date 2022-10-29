/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/29 03:52:22 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	token_len(t_main *m, t_node *l)
{	
	size_t	len;

	len = 0;
	m->type = ((t_lexer *)l->data)->type;
	while (l && (((t_lexer *)l->data)->type == m->type
			|| ((t_lexer *)l->data)->type == T_SPACE))
	{
		len++;
		l = l->next;
	}
	printf("tokenlen == %lu\n", len);
	return (len);
}

void	build_token(t_main *m)
{
	m->buf = NULL;
	m->i = 0;
	m->buf = xmalloc(sizeof(char) * (token_len(m, m->tmp) + 1));
	while (m->tmp && (((t_lexer *)m->tmp->data)->type == m->type
			|| ((t_lexer *)m->tmp->data)->type == T_SPACE))
	{	
		m->buf[m->i] = ((t_lexer *)m->tmp->data)->arg;
		m->tmp = m->tmp->next;
		m->i++;
	}
	m->buf[m->i] = '\0';
//	m->buf = ft_strtrim(m->buf, " ");
	printf("m->buf = [%s]\n", m->buf);
}

t_token	*fill_token(t_main *m)
{
	t_token		*content;

	content = (t_token *)ft_calloc(1, (sizeof(t_token)));
	build_token(m);
	content->av = shell_splitter(m->buf, m);
	free(m->buf);
	return (content);
}

t_token	*expand_tokens(t_main *m)
{
	t_token		*content;

	content = (t_token *)ft_calloc(1, (sizeof(t_token)));
	control_operator(content, m);
	printf("operator = %d\n", content->id);
	if (content->id == O_STDIN_REDIR || content->id == O_DELEM)
		m->tmp_b = m->tmp_b->next;
	else if (content->id != O_CMD)
		m->tmp_b = m->tmp_b->prev;
	content->av = ((t_token *)m->tmp_b->data)->av;
//	m->tmp_b = m->tmp_b->next;
//	if (content->is_redir)
//		expand_io(m, content);
	if (content->is_piped) 
		pipe(content->pipe);
	content->bin_path = NULL;
	return (content);
}

int	create_tokens(t_main *m)
{
	m->tmp = m->lexicon;
	if (!m->tmp)
		return (0);
	m->tokens = NULL;
	m->tmp_b = NULL;
	m->i = 0;
	m->state = S_DEFAULT;
	while (m->tmp)
	{
		while (m->tmp && ((t_lexer *)m->tmp->data)->type == T_SPACE)
			m->tmp = m->tmp->next;
		putback_node(&m->tmp_b, new_node(fill_token(m)));
	}
	while (m->tmp_b)
	{
		putback_node(&m->tokens, new_node(expand_tokens(m)));
		if (m->tmp_b)
			m->tmp_b = m->tmp_b->next;
	}
	free_parser(m->tmp_b);
	return (1);
}
