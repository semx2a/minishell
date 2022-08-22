/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:03:40 by abonard           #+#    #+#             */
/*   Updated: 2022/08/22 17:34:19 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

//			read, write, exit, getcwd, chdir, read, close, access, stat, unlink
//			execve, dup, dup2, pipe, isatty, ttyname, ttyslot, tcsetattr, 
//			tcgetattr
# include <unistd.h>

//			printf, filedes, readline, perror
# include <stdio.h>

//			malloc, free, exit, getenv
# include <stdlib.h>

//			strerror
# include <string.h>

//			errors
# include <errno.h>

//			opendir, readdir, closedir
# include <dirent.h>

//			ioctl
# include <sys/ioctl.h>

//			tcsetattr, tcgetattr
# include <termios.h>

//			wait3, wait4
# include <sys/resource.h>
# include <sys/time.h>

//			open, kill, wait, waitpid, wait3, wait4, stat, opendir, closedir
# include <sys/types.h>

//			open, wait, waitpid, wait3, wait4
# include <sys/wait.h>

//			stat
# include <sys/stat.h>

//			open
# include <fcntl.h>

//			sigaction, sigemptyset, sigaddset, kill
# include <signal.h>

//			readline
# include <readline/readline.h>
# include <readline/history.h>

//			libft
# include "../../libft/inc/libft.h"

//			minishell headers
# include "structures.h"
# include "functions.h"
# include "macros.h"

#endif
