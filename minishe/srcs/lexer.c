/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/22 18:33:59 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
		operators:
		- control operators: 		‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’,
									‘|&’, ‘(’, or ‘)’.
		- redirection operators :	< << > >> | &
*/

int		token_scan(char *token)
{

}

void	lexer(t_main *m)
{
	int		i;
	char	**tokens;

	i = 0;
	m->args = xmalloc(sizeof(t_stack));
	init_stack(m->args);
	tokens = ft_split(m->line, ' ');
	while (tokens[i] != 0)
	{
		if (token_scan(tokens[i]) == WORD)
			put_back(m->args, WORD, tokens[i]);
		else if (token_scan(tokens[i]) == OPERATOR)
			put_back(m->args, OPERATOR, tokens[i]);
		i++;
	}
}
