/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:41:28 by abonard           #+#    #+#             */
/*   Updated: 2022/10/05 13:41:29 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_envlen(t_env *env)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	*get_cont(char *name_var, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(name_var, tmp->var) == 0)
			return (tmp->cont);
		tmp = tmp->next;
	}
	return (NULL);
}

 char	**ft_env_to_tab(t_env *env)
{
	char	**tab;
	t_env	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = env;
	len = ft_envlen(tmp);
	tab = xmalloc(sizeof(char *) * (unsigned long)len);
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->total);
		if (tab[i] == NULL)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

t_env	*fill_env(char *is_env)
{
	t_env	*new;
	char	**tab;

	new = xmalloc(sizeof(t_env) * 1);
	new->next = NULL;
	new->total = is_env;
	tab = ft_split(new->total, '=');
	new->var = ft_strdup(tab[0]);
	new->cont = ft_strdup(tab[1]);
	if (tab == NULL || new->var == NULL || new->cont == NULL)
		return (NULL);
	ft_free_stab(tab);
	return (new);
}

t_env	*put_env(char **envp)
{
	int		i;
	t_env	*tmp;
	t_env	*res;

	i = 1;
	res = fill_env(envp[0]);
	tmp = res;
	while (envp[i])
	{
		tmp->next = fill_env(envp[i]);
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp);
	}
	env = NULL;
	free(env);
}

t_env *ft_add_new(char *varname, char *value)
{
	t_env *new;

	new = xmalloc(sizeof(t_env) * 1);
	new->var = ft_strdup(varname);
	new->cont = ft_strdup(value);
	new->total = ft_strjoin(varname, "=");
	new->total = ft_strjoin(new->total, value);
	new->next = NULL;
	return (new);
}

int	ft_add_env(char *namevar, char *value, t_env *env)
{
	t_env	*newline;
	t_env	*tmp;

	tmp = env;
	if (!tmp)
		return (1);
	if (ft_strcmp(env->var, "") == 0 && ft_strcmp(env->cont, "") == 0)
	{
		free(env->var);
		free(env->cont);
		env->var = ft_strdup(namevar);
		env->cont = ft_strdup(value);
		env->total = ft_strdup(env->var);
		env->total = ft_strjoin(env->total, "=");
		env->total = ft_strjoin(env->total, env->cont);
		if (env->var == NULL || (value && env->cont == NULL))
			return (1);
		return (0);
	}
	newline = ft_add_new(namevar, value);
	if (newline == NULL)
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newline;
	return (0);
}

int ft_create_o_replace(char *namevar, char *value, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->var, namevar) == 0)
		{
			free(tmp->cont);
			tmp->cont = ft_strdup(value);
			if (tmp->cont == NULL)
				return (1);
			return (0);
		}
		tmp = tmp->next;
	}
	if ((ft_add_env(namevar, value, env)) == 1)
		return (1);
	return (0);
}
