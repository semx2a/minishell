/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:21 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/15 19:51:57 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_operator	identify_operator(char *buf, char **operators)
{
	t_operator	i;

	i = 0;
	while (operators[(int)i])
	{
		if (!ft_strncmp(operators[(int)i], buf, ft_strlen(buf)))
			return (i);
		i++;
	}
	return (O_CMD);
}

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
	while (l && (m->type == ((t_lexer *)l->data)->type
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
	content->av = (char **)xmalloc(sizeof(char *) * 2);
	content->av[0] = ft_strdup(buf);
	content->av[1] = 0;
	content->bin_path = NULL;
	content->is_piped = 0;
	content->is_redir = 0;
	return (content);
}

int	parser(t_main *m)
{	
	t_node	*tmp;

	m->i = 0;
	tmp = m->lexicon;
	while (tmp)
	{	
		putback_node(&m->tokens, new_node(fill_parser(build_token(m, tmp), m)));
		free(m->buf);
		while (m->i--)
			tmp = tmp->next;
	}
	free_nodes(&m->lexicon, &free);
	return (1);
}
