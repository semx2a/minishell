/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/21 18:54:13 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

size_t	token_len(t_main *m, t_node *l)
{	
	t_node	*tmp;
	size_t	len;

	len = 0;
	tmp = l;
	m->type = ((t_lexer *)tmp->data)->type;
	while (tmp && (m->type == ((t_lexer *)tmp->data)->type
			|| ((t_lexer *)tmp->data)->type == T_SPACE))
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char	*build_token(t_main *m, t_node *l)
{
	m->buf = NULL;
	m->i = 0;
	m->buf = xmalloc(sizeof(char) * (token_len(m, l) + 1));
	while (l && (((t_lexer *)l->data)->type == m->type
			|| ((t_lexer *)l->data)->type == T_SPACE))
	{
		m->buf[m->i] = ((t_lexer *)l->data)->arg;
		l = l->next;
		m->i++;
	}	
	m->buf[m->i] = '\0';
	m->buf = ft_strtrim(m->buf, " ");
	return (m->buf);
}

t_parser	*fill_parser(char *buf, t_main *m)
{
	t_parser	*content;

	content = xmalloc(sizeof(t_parser));
	content->id = identify_operator(buf, m->operators);
	content->av = fill_stab(buf, m);
	content->is_piped = 0;
	content->is_redir = 0;
	content->bin_path = NULL;
	free(m->buf);
	return (content);
}
