/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:07:26 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 21:27:54 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

int	ft_lstatcode(void)
{
	//Exit status 0 :  It tells you that your latest command or script executed successfully.
	//Exit status 1: "impermissible operations."
	//Exit status 2: a shell warning of "Permission denied" results
	//Exit status 126: This permission problem is not one of access, but one of setting, as in mode. To get rid of this error and receive an exit status of 0 instead, issue chmod +x blah.sh.
	//Exit status 127:	-Either the command doesn't exist, or the command isn't in your path ($PATH).
	//					-you attempt to execute a command that is in your current working directory
	//Exit status 128:  the response received when an out-of-range exit code is used in programming
	//Exit status 130: If you're running a program or script and press Ctrl-C to stop it, your exit status is 130.
	//Exi status 255: command "ip"
	

}

int	ft_echo(t_main *m)
{
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	if (m->o.cmd_flags[1] == NULL)
		printf("\n");
	else if (ft_strcmp(m->o.cmd_flags[1], "$?") == 0)
		return(ft_lstatcode());
	else
		printf("%s\n",  m->o.cmd_flags[1]);
	return (0);
}

int	ft_pwd(char **envp)
{
	char	*path;

	(void)envp;
	path = getenv("PWD");
	if (path == NULL)
	{
		ft_putstr_fd("variable not found\n", 2);
		return (1);
	}
	printf("%s\n", path);
	return (0);
}

int	ft_cd(t_main *m)
{
	m->o.cmd_flags = ft_split(m->o.cmds[0], ' ');
	if (chdir(m->o.cmd_flags[1]) != 0)
	{
		ft_putstr_fd("No such file or directory: No such file or directory\n", 2);
		return (1);
	}
	return (0);
}