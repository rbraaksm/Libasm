/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 09:41:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/08 22:17:58 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BUFFER_SIZE 512

void	ft_list_remove_if2(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;
	// void *data_ref = "5";
	int i = 0;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
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

void	list_add_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (*alst)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*alst = new;
}

t_list	*list_new(void *data)
{
	t_list		*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void	print_lists(t_list *list)
{
	int i;
	int s;

	i = 0;
	s = ft_list_size(list);
	while (list)
	{
		printf("element_%d_data = %s\n", i++, (char*)list->data);
		list = list->next;
	}
	printf("\033[0;36mList size = %d\n\033[0;0m", s);
}
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

void	ft_list_push_front_check(void)
{
	t_list	*list;
	t_list	*list_start;
	t_list	*list_next;
	t_list	*list_last;
	t_list	*new;
	t_list	*test;
	void *data_ref = "5";
	// test = &list_start;
	// list_start = malloc(sizeof(t_list) );
	// list_next = malloc(sizeof(t_list));
	// list_last = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	// list_start->data = "3";
	// list_start->next = list_next;
	// list_next->data = "2";
	// list_next->next = list_last;
	// list_last->data = "1";
	// list_last->next = 0;
	new->data = "NEW";
	// list = malloc(sizeof(t_list*));
	list_add_back(&list, list_new(ft_strdup("5")));
	list_add_back(&list, list_new(ft_strdup("0")));
	list_add_back(&list, list_new(ft_strdup("2")));
	list_add_back(&list, list_new(ft_strdup("5")));
	list_add_back(&list, list_new(ft_strdup("8")));
	list_add_back(&list, list_new(ft_strdup("7")));
	list_add_back(&list, list_new(ft_strdup("4")));
	printf("\nOriginal list content:\n");
	print_lists(list);
	printf("\nList after ft_list_push_front:\n");
	ft_list_push_front(&list, new->data);
	print_lists(list);
	printf("\nft_list_sort\n");
	ft_list_sort(&list, &strcmp);
	print_lists(list);
	printf("\nft_list_remove_if\n");
	// ft_list_remove_if2(&list, "5", &strcmp);
	// ft_list_remove_if2(&list, "5", &strcmp);
	ft_list_remove_if(&list, "5", &strcmp);
	print_lists(list);
	// free(test);
	// free(list_start.data);
	// free(list_next.data);
	// // free(list_last.data);
	// free(new.data);
}

// void	ft_atoi_base_check(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	int		i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		break ;
// 	}
// }

int		main(void)
{
	// ft_atoi_base_check();
	ft_list_push_front_check();
	// while (1)
	// {

	// }
	return (0);
}

// void	list_add_back(t_list **alst, t_list *new)
// {
// 	t_list	*tmp;

// 	if (!alst || !new)
// 		return ;
// 	if (*alst)
// 	{
// 		tmp = *alst;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = new;
// 	}
// 	else
// 		*alst = new;
// }

// t_list	*list_new(void *data)
// {
// 	t_list		*lst;

// 	if (!(lst = malloc(sizeof(t_list))))
// 		return (NULL);
// 	lst->data = data;
// 	lst->next = NULL;
// 	return (lst);
// }

// void	print_list(t_list *list)
// {
// 	t_list	*tmp;

// 	tmp = list;
// 	while (tmp)
// 	{
// 		printf("%s\n", tmp->data);
// 		tmp = tmp->next;
// 	}
// }

// int		main(void)
// {
// 	t_list	*list;
// 	int i = 5;

// 	list = malloc(sizeof(t_list *));
// 	// list = NULL;
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("2")));
// 	list_add_back(&list, list_new(strdup("5")));
// 	list_add_back(&list, list_new(strdup("2")));
// 	list_add_back(&list, list_new(strdup("8")));
// 	list_add_back(&list, list_new(strdup("0")));
// 	list_add_back(&list, list_new(strdup("0")));
// 	list_add_back(&list, list_new(strdup("1")));
// 	printf("before:\n");
// 	print_list(list);
// 	printf("\n");
// 	ft_list_remove_if(list, &i, ft_strcmp);
// 	printf("after:\n");
// 	print_list(list);
// }