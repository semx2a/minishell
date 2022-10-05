/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:16 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 20:17:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_operator(char c, t_main *m)
{	
	if ((!ft_isprint(c) || c == ' ') && m->state == DEFAULT)
		return (O_SPACE);
	if ((c == '$' && m->quote == DOUBLE_Q && m->state == OPEN_QUOTE)
		|| (ft_strchr("|&()><*?[]$\'\"#", c) && m->state == DEFAULT))
		return (OPERATOR);
	return (WORD);
}

int	is_quote(char c, t_main *m)
{
	if ((c == DOUBLE_Q || c == SINGLE_Q) && m->state == DEFAULT)
	{
		m->quote = c;
		return (OPEN_QUOTE);
	}
	if (c == m->quote && m->state == OPEN_QUOTE)
		return (CLOSE_QUOTE);
	return (DEFAULT);
}

int	token_scan(t_main *m, char token)
{
	if (is_operator(token, m))
		return (OPERATOR);
	return (WORD);
}

size_t	tokenlen(t_stack *lexicon)
{
	t_node	*tmp;
	size_t	len;
	int		status;

	tmp = lexicon->head;
	len = 0;
	status = 0;
	while (tmp)
	{
		if (tmp->type == O_SPACE)
			tmp = tmp->next;
		if (len == 0 && tmp->type == status)
			len++;
		else if (tmp->type != status)
		{
			len++;
			status = tmp->type;
		}
		printf("len = %lu | %s\n", len, tmp->arg);
		tmp = tmp->next;

	}
	return (len);
}
