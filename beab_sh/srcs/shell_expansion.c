/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 18:47:23 by seozcan          ###   ########.fr       */
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

int	expansion(t_main *m)
{
//	if (type_occurrences(m->tokens, O_STDIN_REDIR) != NULL)
//		ft_open(&m->fd_in, find_arg(m->tokens, INFILE_ID), O_RDONLY, NULL);
//	if (type_occurrences(m->tokens, O_STDOUT_REDIR) != NULL)
//		ft_open(&m->fd_out, find_arg(m->tokens, OUTFILE_ID),
//			O_CREAT | O_TRUNC | O_WRONLY, 0644);
	m->paths = ft_split(get_cont("PATH", m->env), ':');
	m->index = 0;
	return (1);
}
