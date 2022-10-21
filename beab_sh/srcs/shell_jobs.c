/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_jobs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:44:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/21 18:56:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* void	ft_process(t_main *m, t_node *p) */
/* { */
/* 	p->pid = fork(); */
/* 	if (p->pid == -1) */
/* 		ft_error(); */
/* 	else if (p->pid > 0) */
/* 	{ */
/* 		waitpid(p->pid, 0, 0); */
/* 		kill(p->pid, SIGTERM); */
/* 	} */
/* 	else if (p->pid == 0) */
/* 	{ */
/* 		if (m->pipe_nb > 0) */
/* 		{	 */
/* 			pipes(m); */
/* 			if (p->id == O_PIPE) */
/* 				execute(m); */
/* 			else if (p->id == O_DELEM) */
/* 				heredoc(m); */
/* 		} */
/* 		else */
/* 			execute(m); */
/* 	} */
/* } */


int	process_args(t_main *m)
{	
	t_node	*tmp;

	m->state = S_DEFAULT;
	m->lexicon = fill_lexer(m);
	if (m->state == S_OPEN_QUOTE)
	{
		ft_putstr_fd("Error: Open quote found\n", 2);
		free_nodes(&m->lexicon, &free);
		return (0);
	}
	m->i = 0;
	tmp = m->lexicon;
	m->tokens = NULL;
	while (tmp)
	{	
		type = ((t_lexer *)tmp->data)->type;
		if (type == T_WORD)
		{
			putback_node(&m->tokens,
				new_node(fill_parser(build_token(m, tmp), m)));
			while (m->i--)
				tmp = tmp->next;
		}
		else if (type = T_OPERATOR)
			expand(&m->tokens->data, m)
	}
	free_nodes(&m->lexicon, &free);
	m->paths = ft_split(get_cont("PATH", m->env), ':');
	return (1);
}

void	job(t_main *m)
{
	if (!process_args(m))
	{
		free_parser(m->tokens);
		return ;
	}
	print_parser(m->tokens);
/*	m->index = 0;
	while (m->tokens)
	{	
		if (is_builtin(p->av[0], m->builtins) == 1)
			exec_builtin(m);
		else
		{
			ft_process(m, ((t_parser *)m->tokens->data)->content;
			m->index++;
		}
		m->tokens = p->next;

	}
	waitpid(-1, NULL, 0); */
	free_parser(m->tokens);
}
