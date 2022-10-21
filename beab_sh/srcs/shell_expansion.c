/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/21 18:55:00 by seozcan          ###   ########.fr       */
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

t_redir	*fill_redir(char *buf, t_main *m)
{
	t_redir	*data;

	data = xmalloc(sizeof(t_redir));
	expand_io(((t_redir *)content->redir)->data)
	data->id = 0;
	data->path = NULL;
	return (data);
}

void	expand(t_parser *content, t_main *m)
{
	content->id = identify_operator(buf, m->operators);
	if (content->id < O_STDIN_REDIR)
	{
		content->is_piped = 1;
		pipe(content->pipe);
	}
	else if (content->id >= O_STDIN_REDIR && content->id <= O_APPEN)
	{
		content->is_redir = 1;
		putback_node(&content->redir, new_node(fill_redir(m)));
	}
	data_sym->bin_path = get_cmd(m_sym->paths, data_sym->av[0]);
}

