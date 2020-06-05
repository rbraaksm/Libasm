/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 11:30:47 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/04 11:36:03 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	t_list	*search;
	void	*tmpval;

	list = *begin_list;
	if (!list)
		return ;
	while (list->next)
	{
		search = list->next;
		while (search)
		{
			if (cmp(list->data, search->data) > 0)
			{
				tmpval = list->data;
				list->data = search->data;
				search->data = tmpval;
			}
			search = search->next;
		}
		list = list->next;
	}
}