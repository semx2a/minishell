/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:49:51 by seozcan           #+#    #+#             */
/*   Updated: 2022/09/26 19:21:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H

# define FUNCTIONS_H

# include "minishell.h"

//				PIPEX
int		pipex(int ac, char **av, char **envp);

// 				pipex_cmds.c
void	ft_process(t_obj o, char **envp);

// 				pipex_utils.c
void	ft_error(const char *str);
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);

//				lexer.c
void	lexer(t_main *m);

//				env_utils.c
int		ft_get_len_env(t_env *env);
char	*get_cont(char *name_var, t_env *env);
char	**ft_list_to_tab(t_env *env);
t_env	*fill_env(char *is_env);
t_env	*ft_put_env(char **envp);

//				builtins.c
int		ft_env(t_env *env);
int		ft_pwd(t_env *env);
int		ft_exit(t_env *env, char **cmds);

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
void	ft_error(const char *str);
void	*xmalloc(size_t size);
long	ft_atoli(const char *str);

//				multi_split.c
char	**multi_split(char *str, char *charset);

#endif
