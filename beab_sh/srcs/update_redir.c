/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:17:59 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 22:28:19 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_redir	*new_node_redir(t_operator type, char *str)
{
	t_redir	*new;

	new = xmalloc(sizeof(t_node));
	new->path = str;
	new->type = type;
	pipe(new->fd);
	new->next = NULL;
	return (new);
}

void	print_redir(t_redir *r)
{
	t_redir	*tmp;
	int		i;

	tmp = r;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d\n", i, tmp->id);
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}

void	free_redir(t_redir *p)
{
	t_redir	*tmp;

	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	p = NULL;
	free(p);
}

size_t	redir_size(t_redir *p)
{
	size_t		size;
	t_redir		*tmp;

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