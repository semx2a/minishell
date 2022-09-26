/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:19:54 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/26 21:30:10 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static size_t	ft_scan(char c, char *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

static size_t	ft_word_count(char *str, char *charset)
{
	size_t	wcount;
	size_t	i;

	wcount = 0;
	i = 0;
	while (str[i])
	{
		if (ft_scan(str[i + 1], charset) && (!ft_scan(str[i], charset)))
			wcount++;
		if (ft_scan(str[i], charset))
			wcount++;
		i++;
	}
	return (wcount);
}

static void	ft_strcat(char **dest, char *str, char *charset)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tabs;

	i = 0;
	tabs = 0;
	while (str[i])
	{
		if (!ft_scan(str[i], charset))
		{
			j = i;
			while (!ft_scan(str[j], charset))
				j++;
			dest[tabs++] = ft_strtrim(ft_substr(str, i, j - i), " ");
			i = j - 1;
		}
		if (ft_scan(str[i], charset))
		{
			j = i;
			while (ft_scan(str[j], charset))
				j++;
			dest[tabs++] = ft_strtrim(ft_substr(str, i, j - i), " ");
			i = j - 1;
		}
		if (str[i + 1] == '\0')
			break ;
		i++;
	}
}

char	**multi_split(char *str, char *charset)
{
	size_t		wcount;
	char		**dest;

	wcount = ft_word_count(str, charset);
	dest = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (dest == NULL)
		return (NULL);
	dest[wcount] = 0;
	ft_strcat(dest, str, charset);
	return (dest);
}
