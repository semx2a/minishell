/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 20:35:44 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_parser	*new_node_parser(t_operator type, char *str)
{
	t_parser	*new;

	new = xmalloc(sizeof(t_parser));
	new->av = ft_split(str, ' ');
	new->id = type;
	if (type == O_PIPE)
	{
		new->is_piped = 1;
		pipe(new->pipe);
	}
	new->next = NULL;
	return (new);
}

void	print_parser(t_parser *p)
{
	t_parser	*tmp;
	int			i;
	int			j;

	tmp = p;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d av[%i] = %s\n", i, tmp->id, 0, tmp->av[0]);
		j = 1;
		while (tmp->av[j])
		{
			printf("                 av[%i] = %s\n", j, tmp->av[j]);
			j++;
		}
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}

void	free_parser(t_parser *p)
{
	t_parser	*tmp;

	while (p)
	{
		tmp = p;
		if (tmp->is_piped == 1)
		{
			close(tmp->pipe[0]);
			close(tmp->pipe[1]);
		}
		if (tmp->bin_path)
			free(tmp->bin_path);
		ft_free_stab(tmp->av);
		if (tmp->redir)
			free_redir(tmp->redir);
		p = p->next;
		free(tmp);
	}
	p = NULL;
	free(p);
}

size_t	parser_size(t_parser *p)
{
	size_t		size;
	t_parser	*tmp;

	size = 0;
	tmp = p;
	if (p)
	{
		if (tmp)
		{
			while (tmp)
			{
				tmp = tmp->next;
				size++;
			}
			return (size);
		}
	}
	return (0);
}
