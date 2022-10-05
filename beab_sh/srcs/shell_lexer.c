/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:30:00 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/29 20:50:36 by seozcan          ###   ########.fr       */
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

size_t	is_in_quotes(char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	printf("%s\n", s);
//	while (s[i])
//	{
	if ((s[i] == DOUBLE_Q || s[i] == SINGLE_Q) && s[i + 1] != '\0')
	{
		j = i + 1;
		while (s[j])
		{
			if (s[j] == s[i])
				return (j + 1);
			j++;
		}
		return (0);
	}
//		i++;
//	}
	return (0);
}

static char	**ft_strs(char const *s, int c)
{
	size_t	i;
	size_t	j;
	char	**dest;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == DOUBLE_Q || s[i] == SINGLE_Q)
			i += is_in_quotes((char *)(s) + i) - 1;
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			j++;
		i++;
	}
	printf("#words = %lu\n", j);
	printf("strs ok\n\n");
	printf("_____________\n\n");
	dest = (char **)xmalloc(sizeof(char *) * (j + 1));
	dest[j] = 0;
	return (dest);
}

char	**tokenizr(char *src, int c)
{
	unsigned int	i;
	unsigned int	j;
	size_t			k;
	char			**dst;

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
			printf("i = %u\n", i);
			j += (unsigned int)is_in_quotes(src + i);
			printf("first j = %u\n", j);
			if (i == j)
				while (src[j] != c && src[j])
					j++;
			printf("second j = %u\n", j);
			printf("k = %lu\n", k);
			dst[k++] = ft_substr(src, i, j - i);
			i = j - 1;
		}
		if (src[i + 1] == '\0')
			break ;
		printf("_____________\n\n");
		i++;
	}
	return (dst);
}

int	token_scan(char *token)
{
	int		i;

	i = 0;
	if (is_in_quotes(token))
		return (WORD);
	else
	{
		while (token[i])
		{
			if (ft_strchr("\t \n|&;()><", token[i]))
				return (OPERATOR);
			i++;
		}
	}
	return (WORD);
}

void	lexer(t_main *m)
{
	int		i;
	char	**tokens;
//	char	*charset;

	i = 0;
	m->args = xmalloc(sizeof(t_stack));
	init_stack(m->args);
//	charset = ft_strdup(" \'\"");
//	tokens = multi_split(m->line, charset);
	tokens = tokenizr(m->line, ' ');
	while (tokens[i] != 0)
	{
		if (token_scan(tokens[i]) == WORD)
			put_back(m->args, WORD, ft_strdup(tokens[i]));
		else
			put_back(m->args, OPERATOR, ft_strdup(tokens[i]));
		i++;
	}
	ft_free_stab(tokens);
}
