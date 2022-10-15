/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/15 20:18:13 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//char	*find_args(t_parser *p, int id)
//{
//	t_parser	*tmp;
//
//	tmp = p;
//	while (tmp)
//	{
//		if (tmp->type == id)
//			return (tmp->av[]);
//		tmp = tmp->next;
//	}
//	return (NULL);
//}

size_t	type_occurrences(t_parser *p, t_operator id)
{
	t_parser	*tmp;
	size_t		len;

	tmp = p;
	len = 0;
	while (tmp)
	{
		if (tmp->id == id)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

int	identify_redir(t_main *m)
{
	if (type_occurrences(m->tokens, O_STDIN_REDIR) != NULL)
		ft_open(&m->fd_in, find_arg(m->tokens, INFILE_ID), O_RDONLY, NULL);
	if (type_occurrences(m->tokens, O_STDOUT_REDIR) != NULL)
		ft_open(&m->fd_out, find_arg(m->tokens, OUTFILE_ID),
			O_CREAT | O_TRUNC | O_WRONLY, 0644);
}

char	**fill_stab(t_lexer *content, t_main *m)
{
	char	**new;

	new = NULL;
	m->i = 0;
	new = ft_split();
	while (m->i)
	{
		new[m->i] = ft_substr(content->arg, m->i, m->j);
		new[m->i] = ft_strtrim(new[m->i], " ");
		m->i++;
	}
	newz[m->i] = 0;
	return (m->buf);
}

t_parser	*update_tokens(t_lexer *content, t_main *m)
{
	content = xmalloc(sizeof(t_parser));
	content->id = identify_operator(buf, m->operators);
	content->av = fill_stab(content, m);
	content->bin_path = get_cmd(m->paths, m->tokens->av[0]);
	content->is_piped = 0;
	content->is_redir = 0;
	return (content);
}

int	expansion(t_main *m)
{	
	t_node	*tmp;

	m->i = 0;
	tmp = m->parser;
	while (tmp)
	{	
		((t_parser)tmp->data) = update_tokens(((t_parser)tmp->data), m);
		tmp = tmp->next;
	}
	m->paths = ft_split(get_cont("PATH", m->env), ':');
	m->index = 0;
	return (1);
}
