/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/11 15:57:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				jobs_execution.c
void	execute(t_main *m);
int		exec_builtin(t_main *m);

//				jobs_pipes.c
void	ft_assign_pipes(t_obj *o);
void	pipes(t_obj *o);

//				utils_builtins.c
int		is_builtin(char **cmds);

//				pipes.c
void	ft_assign_pipes(t_obj *o);
void	pipes(t_obj *o);

//				shell_builtins.c
int		ft_env(t_env *env);
int		ft_pwd(t_env *env);

//				shell_cd
int		ft_cd(t_main *m, bool is_forked);

//				shell_echo
int		ft_echo(t_main *m);

//				shell_exit
int		ft_exit(t_main *m, bool is_forked);

//				shell_expansion.c
int		expansion(t_main *m);

//				shell_export.c
int		ft_export(t_main *m, bool is_forked);

// 				shell_flush.c
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);
void	ft_flush(t_main *m);

//				shell_init.c
void	shell_init(t_main *m, char **envp);

//				shell_io.c
void	in_n_out(t_main *m);
void	heredoc(t_main *m);

//				shell_jobs.c
void	job(t_main *m);

//				shell_lexer.c
int		lexer(t_main *m);

//				shell_parser.c
int		parser(t_main *m);

//				shell_signals.c
int		shut_signals(int fork);
int		set_signals(void);

//				shell_unset.c
int		ft_unset(t_main *m, bool is_forked);

//				utils_builtins.c
int		is_builtin(char **cmds);

//				utils_env.c
t_env	*put_env(char **envp);
void	free_env(t_env *env);
t_env	*ft_add_new(char *varname, char *value);
int		ft_add_env(char *namevar, char *value, t_env *env);
int		ft_create_o_replace(char *namevar, char *value, t_env *env);

//				utils_env2.c
int		ft_envlen(t_env *env);
char	*get_cont(char *name_var, t_env *env);
char	**ft_env_to_tab(t_env *env);
t_env	*fill_env(char *is_env);
t_env	*ft_if_env_empty(void);

//				shell_builtins.c
int		ft_checkname(char *namevar);
void	ft_swap_list(t_env **begin, t_env *last);
void	ft_sort_env(t_env **begin);
void	ft_print_declare(t_env *env, bool is_forked);
int		ft_check_and_export(char *namevar, char *value, t_env *env,
			bool is_forked);

//				utils_lexer.c
int		is_operator(char c, t_main *m);
int		is_quote(char c, t_main *m);
int		token_scan(t_main *m, char token);
size_t	token_len(t_main *m, t_node *a);

//				utils_multi_split.c
char	**multi_split(char *str, char *charset);

//				utils_stack_update.c
void	put_back(t_stack *stack, int type, char *str);
void	put_front(t_stack *stack, int type, char *str);
void	print_list(t_stack *stack);

//				stack_init.c
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
size_t	stack_size(t_stack *stack);

//				utils.c
/* void	ft_error(const char *str); */
void	ft_error(void);
void	*xmalloc(size_t size);

#endif
