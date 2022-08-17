/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:44:01 by seozcan           #+#    #+#             */
/*   Updated: 2022/05/06 15:44:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	**allocate_tab(int **tab, int size)
{
	int	i;

	i = 0;
	tab = xmalloc(sizeof(int *) * size);
	while (i < size)
	{
		tab[i] = xmalloc(sizeof(int) * 2);
		i++;
	}
	return (tab);
}
