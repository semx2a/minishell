/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:23:41 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:34:55 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**dest;

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
		return (NULL);
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	char				**dest;

	i = 0;
	k = 0;
	dest = ft_strs(s, c);
	if (!dest)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j])
				j++;
			dest[k++] = ft_substr(s, i, j - i);
			i = j - 1;
		}
		if (s[i + 1] == '\0')
			break ;
		i++;
	}
	return (dest);
}
