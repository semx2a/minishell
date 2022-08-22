/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:22:54 by abonard           #+#    #+#             */
/*   Updated: 2022/08/22 19:07:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>

void	ft_sendmessage(char c, int pid)
{
	int		i;
	char	b;

	i = 0;
	b = '\0';
	while (i < 8)
	{
		if (((c >> b) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("OOPS\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("OOPS\n");
				exit(1);
			}
		}
		i++;
		b++;
		usleep(400);
	}
}

int	ft_gimmepid(char *str)
{
	long long int	pid;

	pid = ft_atoi(str);
	printf("PID %lld\n", pid);
	if (pid <= 0 || pid >= 2147483647)
	{
		printf("OMG, IT IS TOO SMALL OR TO BIG ENOUGH FOR ME\n");
		exit(1);
	}
	return (pid);
}

void	ft_check(int signal)
{
	int	fuckleswarnings;

	fuckleswarnings = signal;
	signal = fuckleswarnings;
}

void	ft_sigavailable(void)
{
	if (signal(SIGUSR1, ft_check) == SIG_ERR
		|| signal(SIGUSR2, ft_check) == SIG_ERR)
		exit(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		printf("ERROR: WRONG NUMBER ARGUMENTS\n");
		return (1);
	}
	ft_sigavailable();//verifier les signaux sont dispo
	pid = ft_gimmepid(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		ft_sendmessage(argv[2][i], pid);
		i++;
	}
	ft_sendmessage(argv[2][i], pid);
	return (0);
}
