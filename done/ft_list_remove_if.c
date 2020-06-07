/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_remove_if.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/04 11:30:47 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/05 12:40:01 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp) ())
{
	t_list *head;
	t_list *past;
	t_list *t_remove;

	head = *begin_list;
	past = NULL;
	t_remove = NULL;
	while (head != NULL)
	{
		if ((*cmp)(head->data, data_ref) == 0)
		{
			if (head == *begin_list)
				*begin_list = head->next;
			else
				past->next = head->next;
			t_remove = head;
			head = head->next;
			free(t_remove);
		}
		else
		{
			past = head;
			head = head->next;
		}
	}
}