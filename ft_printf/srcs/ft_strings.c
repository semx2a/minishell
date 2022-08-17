/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:24:31 by seozcan           #+#    #+#             */
/*   Updated: 2021/12/13 21:55:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i] != 0)
			ft_putchar(s[i]);
	else
		i = ft_putstr("(null)");
	return (i);
}

char	*ft_strchr_printf(const char *s, int c)
{
	int		i;
	char	a;

	i = -1;
	a = (char)c;
	while (s[++i])
		if (s[i] == a || (s[i] == '\0' && a == 0))
			return ((char *)s + i);
	return (0);
}
