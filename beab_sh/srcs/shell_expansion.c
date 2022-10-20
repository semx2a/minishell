/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/20 17:43:26 by seozcan          ###   ########.fr       */
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

size_t	type_occurrences(t_node *p, t_operator id)
{
	t_node	*tmp;
	size_t	len;

	tmp = p;
	len = 0;
	while (tmp)
	{
		if (((t_parser *)tmp->data)->id == id)
			len++;
		tmp = tmp->next;
	}
	return (len);
}

void	expand_tokens(void *content, void *m)
{
	t_parser	*data_sym;
	t_main		*m_sym;

	data_sym = (t_parser *){content};
	m_sym = (t_main *){m};
	data_sym->av = fill_stab(data_sym, m_sym);
	data_sym->bin_path = get_cmd(m_sym->paths, data_sym->av[0]);
//	if (identify_pipes())
//		pipe(data_sym->pipe);
//	if (identify_io())
//		expand_io((t_redir *)data_sym->redir->data);
}

int	expansion(t_main *m)
{	
	t_node	*tmp;

	tmp = m->tokens;
	m->paths = ft_split(get_cont("PATH", m->env), ':');
	node_iter(tmp, &expand_tokens, m);
	m->index = 0;
	return (1);
}
