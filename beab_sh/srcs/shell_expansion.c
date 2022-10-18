/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/17 18:04:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*ret;

	if (access(cmd, 0) == 0)
		return (cmd);
	else
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			ret = ft_strjoin(tmp, cmd);
			free(tmp);
			if (access(ret, X_OK) == 0)
				return (ret);
			free(ret);
			paths++;
		}
		ft_putstr_fd("command not found\n", 2);
	}
	return (NULL);
}

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

char	**fill_stab(t_parser *content, t_main *m)
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

void	expand_tokens(void *content, void *m)
{
	t_parser	*data_sym;
	t_main		*m_sym;

	data_sym = (t_parser *)content;
	m_sym = (t_main *)m;
	data_sym->av = fill_stab(data_sym, m_sym);
	data_sym->bin_path = get_cmd(m_sym->paths, data_sym->av[0]);
	if (identify_pipes())
		expand_pipes();
	if (identify_io())
		expand_io();
	content = &data_sym;
	m = &m_sym;
}

int	expansion(t_main *m)
{	
	t_node	*tmp;

	m->i = 0;
	tmp = m->tokens;
	node_iter(tmp, &expand_tokens, &m);
	m->paths = ft_split(get_cont("PATH", m->env), ':');
	m->index = 0;
	return (1);
}
