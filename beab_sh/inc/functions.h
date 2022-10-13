/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/13 20:36:49 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				jobs_execution.c
void		execute(t_main *m);
int			exec_builtin(t_main *m);

//				jobs_pipes.c
void		pipes(t_main *m);

//				shell_builtins.c
int			ft_env(t_env *env);
int			ft_pwd(t_env *env);

//				shell_cd.c
int			ft_cd(t_main *m, bool is_forked);

//				shell_echo.c
int			ft_echo(t_main *m);

//				shell_exit.c
int			ft_exit(t_main *m, bool is_forked);

//				shell_expansion.c
int			expansion(t_main *m);

//				shell_export.c
int			ft_export(t_main *m, bool is_forked);

// 				shell_flush.c
void		ft_flush(t_main *m);

//				shell_init.c
void		shell_init(t_main *m, char **envp);

//				shell_io.c
void		ft_open(int *fd, char *pathname, int flags, int mode);
void		heredoc(t_main *m);

//				shell_jobs.c
void		job(t_main *m);

//				shell_lexer.c
int			lexer(t_main *m);

//				shell_parser.c
int			parser(t_main *m);

//				shell_signals.c
int			shut_signals(int fork);
int			set_signals(void);

//				shell_unset.c
int			ft_unset(t_main *m, bool is_forked);

//				utils_builtins.c
int			is_builtin(char *cmd, char **builtins);

//				utils_env.c
t_env		*put_env(char **envp);
void		free_env(t_env *env);
t_env		*ft_add_new(char *varname, char *value);
int			ft_add_env(char *namevar, char *value, t_env *env);
int			ft_create_o_replace(char *namevar, char *value, t_env *env);

//				utils_env2.c
int			ft_envlen(t_env *env);
char		*get_cont(char *name_var, t_env *env);
char		**ft_env_to_tab(t_env *env);
t_env		*fill_env(char *is_env);
t_env		*ft_if_env_empty(void);

//				shell_builtins.c
int			ft_checkname(char *namevar);
void		ft_swap_list(t_env **begin, t_env *last);
void		ft_sort_env(t_env **begin);
void		ft_print_declare(t_env *env, bool is_forked);
int			ft_check_and_export(char *namevar, char *value, t_env *env,
				bool is_forked);

//				update_lexer.c
t_lexer		*new_node_lexer(t_types type, char c);
void		print_lexer(t_lexer *l);
void		free_lexer(t_lexer *l);
size_t		lexer_size(t_lexer *l);

//				update_parser.c
t_parser	*new_node_parser(t_operator type, char *str);
void		print_parser(t_parser *p);
void		free_parser(t_parser *p);
size_t		parser_size(t_parser *p);

//				update_redir.c
t_redir		*new_node_redir(t_operator type, char *str);
void		print_redir(t_redir *r);
void		free_redir(t_redir *p);
size_t		redir_size(t_redir *p);

//				utils.c
/* void	ft_error(const char *str); */
void		ft_error(void);
void		*xmalloc(size_t size);

#endif
