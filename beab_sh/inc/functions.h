/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/05 13:55:43 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				shell_init.c
void	shell_init(t_main *m, char **envp);

//				shell_jobs.c
void	job(t_main *m);

//				jobs_execution.c
void	execute(t_main *m);
int		exec_builtin(t_main *m);

//				shell_expansion.c
void	expansion(t_main *m);

//				utils_builtins.c
int		is_builtin(char **cmds);

//				pipes.c
void	ft_assign_pipes(t_obj *o);
void	pipes(t_obj *o);

//				io.c
void	in_n_out(t_main *m);
void	heredoc(t_obj o);

// 				shell_flush.c
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);
void	ft_flush(t_main *m);

//				lexer.c
void	lexer(t_main *m);

//				env_utils.c
int		ft_get_len_env(t_env *env);
char	*get_cont(char *name_var, t_env *env);
char	**ft_env_to_tab(t_env *env);
t_env	*fill_env(char *is_env);
t_env	*put_env(char **envp);
void	free_env(t_env *env);
int     ft_create_o_replace(char *namevar, char *value, t_env *env);


//				shell_builtins.c
int		ft_env(t_env *env);
int		ft_pwd(t_env *env);
int		ft_cd(t_main *m, bool is_forked);
int		ft_echo(t_main *m);
int     ft_exit(t_main *m, bool is_forked);

//				signals.c
int		shut_signals(int fork);
int		set_signals(void);

//				stack_init.c
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);

//				stack_update.c
void	put_back(t_stack *stack, int type, char *arg);
void	put_front(t_stack *stack, int tyoe, char *arg);
void	print_list(t_stack *stack);

//				utils.c
/* void	ft_error(const char *str); */
void	ft_error(void);
void	*xmalloc(size_t size);

//				multi_split.c
char	**multi_split(char *str, char *charset);

#endif
