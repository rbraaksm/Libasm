/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 09:41:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/08 15:09:19 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BUFFER_SIZE 512

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

void	ft_list_push_front_check(void)
{
	t_list	*list_start;
	t_list	*list_next;
	t_list	*list_last;
	t_list	*new;
	t_list	test;
	char *i = "4";

	// test = &list_start;
	list_start = malloc(sizeof(t_list));
	list_next = malloc(sizeof(t_list));
	list_last = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));
	list_start->data = "3";
	list_start->next = list_next;
	list_next->data = "2";
	list_next->next = list_last;
	list_last->data = "1";
	list_last->next = 0;
	new->data = "4";
	printf("\nOriginal list content:\n");
	print_lists(list_start);
	printf("\nList after ft_list_push_front:\n");
	ft_list_push_front(&list_start, new->data);
	print_lists(list_start);
	printf("\nft_list_sort\n");
	ft_list_sort(&list_start, &ft_strcmp);
	print_lists(list_start);
	printf("\nft_list_remove_if\n");
	ft_list_remove_if(&list_start, &i, ft_strcmp);
	print_lists(list_start);
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