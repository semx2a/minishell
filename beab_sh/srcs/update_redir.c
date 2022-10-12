/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:17:59 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/12 18:29:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_redir	put_back_redir(t_redir *r, int type, char *str)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->arg = str;
	new->type = type;
	new->prev = r;
	new->next = NULL;
	return (new)
}

t_redir	put_front_redir(t_redir *r, int type, char *str)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->arg = str;
	new->type = type;
	new->next = r;
	new->prev = NULL;
	return (new);
}

void	print_redir(t_redir *r)
{
	void	*tmp;
	int		i;

	tmp = (void *)r;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d arg = %s\n", i, (t_lexer *)tmp->type, (t_lexer *)tmp->arg);
		printf(" ------------------ \n");
		i++;
		tmp = (void *)tmp->next;
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
	t_redir	*tmp;

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