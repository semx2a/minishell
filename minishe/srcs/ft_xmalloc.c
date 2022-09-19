/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:43:10 by seozcan           #+#    #+#             */
/*   Updated: 2022/08/23 18:03:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	*xmalloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
		ft_error(ERR_MALLOC);
	return (tmp);
}
