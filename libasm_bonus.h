/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libasm_bonus.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 09:38:45 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/08 09:40:42 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H
# include "libasm.h"

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int					ft_atoi_base(char *str, char *base);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list **begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)());
#endif
