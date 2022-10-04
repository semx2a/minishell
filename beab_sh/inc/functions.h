/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/04 18:31:22 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				jobs_execution.c
void	execute(t_main *m, char **envp);
int		exec_builtin(t_main *m, char **envp);

//				jobs_pipes.c
void	ft_assign_pipes(t_obj *o);
void	pipes(t_obj *o);

//				shell_builtins.c
int		ft_env(char **envp);
int		ft_pwd(char **envp);
int		ft_cd(t_main *m);
int		ft_echo(void);

//				shell_expansion.c
void	expansion(t_main *m);

// 				shell_flush.c
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);
void	ft_flush(t_main *m);

//				shell_init.c
void	shell_init(t_main *m);

//				shell_io.c
void	in_n_out(t_main *m);
void	heredoc(t_obj o);

//				shell_jobs.c
void	job(t_main *m, char **envp);

//				shell_lexer.c
void	lexer(t_main *m);

//				shell_parser.c

//				shell_signals.c
int		shut_signals(int fork);
int		set_signals(void);

//				utils_builtins.c
int		is_builtin(char **cmds);

//				utils_env.c
int		ft_get_len_env(t_env *env);
char	*get_cont(char *name_var, t_env *env);
//char	**ft_env_to_tab(t_env *env);
t_env	*fill_env(char *is_env);
t_env	*put_env(char **envp);
void	free_env(t_env *env);

//				utils_lexer.c
int		is_operator(char c, t_main *m);
int		is_quote(char c, t_main *m);
int		token_scan(t_main *m, char token);

//				utils_multi_split.c
char	**multi_split(char *str, char *charset);

//				utils_stack_update.c
void	put_back(t_stack *stack);
void	put_front(t_stack *stack);
void	print_list(t_stack *stack);
t_stack	*stack_alloc(void (f)(t_stack *), size_t len);

//				utils_stack.c
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);

//				utils.c
/* void	ft_error(const char *str); */
void	ft_error(void);
void	*xmalloc(size_t size);

#endif
