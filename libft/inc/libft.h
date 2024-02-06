/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:24:57 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/06 17:30:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

//			malloc, free
# include <stdlib.h>

//			read, write usleep
# include <unistd.h>

//			filedes, printf
# include <stdio.h>

//			NULL, size_t
# include <string.h>

//			macOS string.h
# include <strings.h>

//			errno
# include <errno.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_double_list
{
	t_node	*head;
	t_node	*tail;
}	t_double_list;

int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_atoi(const char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strisdigit(char *str);
int				get_next_line_r(int fd, char **line);
int				**allocate_tab(int **tab, size_t size);
int				ft_error(char *bin_name, char *err_msg);
long			ft_atoli(const char *str);
unsigned int	ft_atoi_hexa(const char *str);

void			ft_bzero(void *s, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin_free(char const *s1, char const *s2);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*xmalloc(size_t size);
void			free_tab(int **tab, int size);
void			ft_free_stab(char **str);
void			print_stab(char **stab);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			**ft_split(char const *s, char c);
char			**multi_split(char const *s, char *charset);
char			*ft_strchr_gnl(const char *s, int c);

size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, char *src, size_t destsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_tablen(char **tab);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::SIMPLE LINKED LISTS::
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_lstsize(t_list *lst);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::DOUBLY LINKED LISTS::
void			putfront_node(t_node **anode, t_node *new);
void			putback_node(t_node **anode, t_node *new);
void			delone_node(t_node *n, void (*del)(void*));
void			free_nodes(t_node **nodes, void (*del)(void*));
void			node_iter(t_node *n, void (*f)(void *));
t_node			*new_node(void *content);
t_node			*last_node(t_node *n);
t_node			*node_map(t_node *nodes, void *(*f)(void *),
					void (*del)(void *));
size_t			node_size(t_node *n);

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::STACKS::
void			putfront_double_list(t_double_list *double_list, void *content);
void			putback_double_list(t_double_list *double_list, void *content);
void			init_double_list(t_double_list *double_list);
void			free_double_list(t_double_list *double_list);
void			reverse(t_double_list *s);
void			rotate(t_double_list *s);
void			swap(t_double_list *s);
void			push(t_double_list *a, t_double_list *b);
size_t			double_list_size(t_double_list *double_list);

#endif
