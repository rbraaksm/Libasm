/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tet.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 17:18:06 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/03 17:21:55 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return (0);
	return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;
	// int i = 0;

	// if (begin_list == NULL || *begin_list == NULL)
	// 	return ;
	tmp = *begin_list;
	while ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		(*begin_list) = tmp;
	}
	lst = *begin_list;
	tmp = *begin_list;
	while (lst != NULL)
	{
		if ((*cmp)(lst->data, data_ref) == 0)
		{
			tmp->next = lst->next;
			free(lst);
			lst = tmp;
			i = 0;
		}
		if (i > 0)
			tmp = tmp->next;
		if (lst != NULL)
			lst = lst->next;
		i++;
	}
}