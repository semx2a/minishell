/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:24:16 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 18:37:00 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_operator(char c, t_main *m)
{
	if (c == '$' && m->quote == DOUBLE_Q && m->state == OPEN_QUOTE)
		return (OPERATOR);
	if (ft_strchr("\t \n|&;()><*?[]$\'\"#\\", c) && m->state == DEFAULT)
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
