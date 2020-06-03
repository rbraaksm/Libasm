/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 14:23:34 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/03 15:42:29 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);

int 		ft_atoi_base(char *str, char *base);
void        ft_list_push_front(t_list **begin_list, void *data);
int         ft_list_size(t_list **begin_list);
void        ft_list_sort(t_list **begin_list, int (*cmp)());
void        ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
#endif
