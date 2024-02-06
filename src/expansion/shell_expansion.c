/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:42:51 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:15:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pull_varvalue(char *varname, t_env *env, int *is_free)
{
	char	*path;

	if (varname[0] == '?' && !varname[1])
	{
		path = ft_itoa(g_status);
		*is_free = 1;
		return (path);
	}
	path = get_cont(varname, env);
	if (path == NULL)
		return ("");
	return (path);
}

void	var_lector(t_token *cursor, char *var, char **reading, t_env *env)
{
	int		i;
	char	*str;
	char	*r;
	int		is_free;

	is_free = 0;
	str = pull_varvalue(var, env, &is_free);
	i = 0;
	r = *reading;
	while (str[i])
	{
		while (str[i] == ' ')
		{
			fill_args(&r, NULL, cursor, NULL);
			i++;
		}
		if (str[i])
			r = ft_strdupcat(r, str + i++, 1);
	}
	*reading = r;
	if (is_free == 1)
		free(str);
}

char	*pull_varname(char *str, int *cursor)
{
	int		i;
	char	*read;

	read = malloc(1);
	if (read == NULL)
		return (NULL);
	read[0] = 0;
	i = 1;
	if (str[i] == '?')
	{
		*cursor += i + 1;
		return (ft_strdupcat(read, "?", 1));
	}
	while (str[i])
	{
		if (!ft_isalnum(str[i]))
		{
			*cursor += i;
			return (read);
		}
		read = ft_strdupcat(read, str + i++, 1);
	}
	*cursor += i;
	return (read);
}

int	expand_var(t_env *env, char **token, int *i, char *str)
{
	char	*varname;
	char	*cont;
	int		j;
	int		is_free;

	is_free = 0;
	if (str[*i] == '$')
	{
		j = 0;
		varname = pull_varname(str + (*i), &j);
		if (ft_strlen(varname) > 0)
		{
			*i += j;
			cont = pull_varvalue(varname, env, &is_free);
			free(varname);
			*token = ft_strdupcat(*token, cont, (int)ft_strlen(cont));
			if (is_free == 1)
				free(cont);
			return (1);
		}
		free(varname);
	}
	return (0);
}

char	*make_token(char *str, int *cursor, char c, t_env *env)
{
	int		i;
	char	*token;

	i = 1;
	token = malloc(1);
	if (token == NULL)
		return (NULL);
	token[0] = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			*cursor += i + 1;
			return (token);
		}
		else if (c == '"' && expand_var(env, &token, &i, str))
			continue ;
		token = ft_strdupcat(token, str + i++, 1);
	}
	free(token);
	token = NULL;
	return (token);
}
