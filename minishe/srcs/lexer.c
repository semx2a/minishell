/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/21 18:36:24 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

typedef enum e_types
{
	WORD,
	OPERATOR,
}	t_types;

typedef struct s_lexer
{
	int		type;
	char	*arg;
}	t_lexer;

void	lexer(const char *line)
{
	(void)line;
}
