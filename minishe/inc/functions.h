/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/29 21:03:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				shell_init.c
void	shell_init(t_main *m);

//				shell_jobs.c
void	ft_job(t_main *m, char **envp);

//				jobs_execution.c
void	execute(t_main *m, char **envp);
int		ft_exec_builtin(t_main *m, char **envp);
int		ft_is_builtin(char **cmds);

//				pipes.c
void	pipes(t_obj o);

//				io.c
void	in_n_out(t_main *m);
void	heredoc(t_obj o);

// 				flushell.c
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);

//				lexer.c
void	lexer(t_main *m);

//				env_utils.c
int		ft_get_len_env(t_env *env);
char	*get_cont(char *name_var, t_env *env);
char	**ft_env_to_tab(t_env *env);
t_env	*fill_env(char *is_env);
t_env	*ft_put_env(char **envp);

//				builtins.c
int		ft_env(char **envp);
int		ft_pwd(char **envp);
int		ft_exit(void);

//				signals.c
int		ft_shutup_signals(int fork);
int		ft_set_signals(void);

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
