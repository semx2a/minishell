/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:45 by seozcan           #+#    #+#             */
/*   Updated: 2022/08/17 15:38:14 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

//			args
# include <stdarg.h>

//			libft
# include "../../libft/inc/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long long int nb, char *base);
int		ft_print_memory(unsigned long long int nb);
int		ft_parse(va_list args, int num_args, const char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_strchr_printf(const char *s, int c);

#endif
