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

/* char	**ft_env_to_tab(t_env *env)
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
} */

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