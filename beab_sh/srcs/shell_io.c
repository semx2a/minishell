/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:02:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/18 17:05:52 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_open(int *fd, char *pathname, int flags, int mode)
{
	*(fd) = open(pathname, flags, mode);
	if (*(fd) == -1)
		ft_error();
}

void	heredoc(t_node *token, t_main *m)
{
	t_redir		*r;
	t_parser	*p;
	char		*buf;

	p = (t_parser *)token->data;
	r = (t_redir *)p->redir->data;
	while (1)
	{	
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		buf = readline();
		if (ft_strcmp(buf, p->av[0]))
			break ;
		/*trouver un moyen de append le buf dans le fichier*/
	}
	pipes(token, m);
	unlink(r->path);
}

void	expand_io(t_redir *data)
{
	if (data->id == O_STDIN_REDIR)
		ft_open(&data->fd, &data->path, O_RDONLY, NULL);
	else if (data->id == O_STDOUT_REDIR || data->id == O_APPEN)
		ft_open(&data->fd, &data->path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	else if (data->id == O_DELEM)
		ft_open(&dat->fd, &data->path, O_TMPFILE | O_WRONLY, 0644);
}

int	identify_io(t_main *m)
{
}
