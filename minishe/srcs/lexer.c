/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/26 15:32:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
		operators:
		- control operators: 		‘||’, ‘&&’, ‘&’, ‘;’, ‘;;’, ‘;&’, ‘;;&’, ‘|’,
									‘|&’, ‘(’, or ‘)’.
		- redirection operators :	< << > >> | &

		A token that doesn’t contain meta-character 
		and isn’t in quotes is a ‘word’. 
		
		A token that contains no quotes and at least
		one meta-character is an ‘operator’.
*/

static char	**ft_strs(char const *s, int c)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			j++;
		i++;
	}
	dest = malloc(sizeof(char *) * (j + 1));
	if (!dest)
		return (0);
	dest[j] = 0;
	return (dest);
}

void	tokenizr(char **dst, char *src, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	dst = ft_strs(src, c);
	if (!dst)
		return (0);
	while (src[i])
	{
		if (src[i] != c)
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			dst[k++] = ft_substr(s, i, j - i);
			i = j - 1;
		}
		if (src[i + 1] == '\0')
			break ;
		i++;
	}
}
// -> find a way to keep double quotes and not cut them out of the resulting string array

int	token_scan(char *token)
{
	int		s_quote;
	int		d_quote;
	int		i;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while (token[i])
	{
		if (token[i] == 34)
			d_quote += 34;
		if (token[i] == 39)
			s_quote += 39;
		if (s_quote == 78 || d_quote == 68)
			return (WORD);
		if (ft_strchr("|&;()><\t \n", (token[i])))
			return (OPERATOR);
		i++;
	}
	return (WORD);
}

void	lexer(t_main *m)
{
	int		i;
	char	**tokens;

	i = 0;
	m->args = xmalloc(sizeof(t_stack));
	init_stack(m->args);
	tokenizr(tokens, m->line, 34);
	while (tokens[i] != 0)
	{
		if (token_scan(tokens[i]) == WORD)
			put_back(m->args, WORD, tokens[i]);
		else
			put_back(m->args, OPERATOR, tokens[i]);
		i++;
	}
	ft_free_stab(tokens);
}
