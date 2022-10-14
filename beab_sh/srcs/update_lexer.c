/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:15:54 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 20:23:00 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* t_lexer	*new_node_lexer(t_types type, char c)
{
	t_lexer	*new;

	new = xmalloc(sizeof(t_lexer));
	new->arg = c;
	new->type = type;
	new->next = NULL;
	return (new);
} */

void	print_lexer(t_node *l)
{
	t_node	*tmp;
	int		i;

	tmp = l;
	i = 0;
	while (tmp)
	{
		printf(" Node #%d type = %d arg = %c\n", i, ((t_lexer *)tmp->data)->type, ((t_lexer *)tmp->data)->arg);
		printf(" ------------------ \n");
		i++;
		tmp = tmp->next;
	}
}

/* void	free_lexer(t_lexer *l)
{
	t_lexer	*tmp;

	while (l)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
	l = NULL;
	free(l);
}

size_t	lexer_size(t_lexer *l)
{
	size_t	size;
	t_lexer	*tmp;

	size = 0;
	tmp = l;
	if (l)
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
} */
