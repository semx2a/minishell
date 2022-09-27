#include "../inc/minishell.h"

int	execute(t_env *env, char **cmds)
{
	char	**paths;
	int		i;
	char	*ultpath;

	i = 0;
	paths = ft_split(get_cont("PATH", env), ':');
	// printf("----->%s", cmds[0]);
	while (paths[i])
	{
		ultpath = ft_strdup(paths[i]);
		ultpath = ft_strjoin(ultpath, "/");
		ultpath = ft_strjoin(ultpath, cmds[0]);
		if (execve(ultpath, cmds, ft_list_to_tab(env)) != -1)
			return (0);
		free(ultpath);
		i++;
	}
	ft_free_stab(paths);
	ft_free_stab(cmds);
	ft_error(ERR_CMD);
	return (-1);
}

// serach for status code for all the builtin created
int	ft_exec_builtin(t_env *env, char **cmds)
{
	int	ret;

	ret = -1;
	if (ft_strcmp("env", cmds[0]) == 0)
		ret = ft_env(env);
	if (ft_strcmp("exit", cmds[0]) == 0)
		ret = ft_exit(env, cmds);
	if (ft_strcmp("pwd", cmds[0]) == 0)
		ret = ft_pwd(env);
	return (ret);
}

	// serach for status code for all the builtin created
int	ft_is_builtin(char **cmds)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("env", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("exit", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("pwd", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("cd", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("export", cmds[0]) == 0)
		ret = 1;
	if (ft_strcmp("unset", cmds[0]) == 0)
		ret = 1;
	return (ret);
}

// ca va beaucoup changer well shit
void	ft_command_handler(t_env *env, char *command)
{
	char	**cmds;
	pid_t	pid;

	pid = fork();
	cmds = ft_split(command, ' ');
	if (pid == -1)
		exit(1);
	else if (pid > 0)
	{
		waitpid(pid, 0, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (ft_is_builtin(cmds) == 1)
			exit(ft_exec_builtin(env, cmds));
		else
			execute(env, cmds);
	}
}

int	ft_minishell(t_main *m)
{
	while (1)
	{
		m->line = readline(">$");
		add_history(m->line);
		lexer(m);
		print_list(m->args);
//		parser();
//		ft_command_handler(m->env, m->line);
		free(m->line);
	}
	rl_clear_history();
}

int	main(int ac, char **av, char **envp)
{	
	t_main	m;

	(void)av;
	if (ac != 1)
		ft_error(ERR_ARGS);
	if (*envp == NULL)
		ft_error(ERR_ENV);
	m = (t_main){0};
	// if (ft_set_signals() == 1)
	//   return (1);
	m.env = ft_put_env(envp);
	ft_minishell(&m);
	return (0);
}
