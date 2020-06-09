/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 09:41:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/09 22:39:03 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>

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
void	ft_list_clear(t_list **begin_list)
{
	t_list *free_me;

	if (*begin_list == NULL)
		return ;
	while (*begin_list)
	{
		free_me = *begin_list;
		*begin_list = (*begin_list)->next;
		free(free_me);
	}
	*begin_list = NULL;
}

void	create_list(t_list **list, int i)
{
	if (i == 1)
	{
		list_add_back(list, list_new("6"));
		list_add_back(list, list_new("5"));
		list_add_back(list, list_new("4"));
		list_add_back(list, list_new("3"));
		list_add_back(list, list_new("2"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("0"));
	}
	if (i == 2)
	{
		list_add_back(list, list_new("1"));
	}
	if (i == 3)
	{
		list_add_back(list, list_new("j"));
		list_add_back(list, list_new("i"));
		list_add_back(list, list_new("z"));
		list_add_back(list, list_new("k"));
		list_add_back(list, list_new("h"));
		list_add_back(list, list_new("y"));
		list_add_back(list, list_new("l"));
		list_add_back(list, list_new("g"));
		list_add_back(list, list_new("x"));
		list_add_back(list, list_new("m"));
		list_add_back(list, list_new("f"));
		list_add_back(list, list_new("w"));
		list_add_back(list, list_new("n"));
		list_add_back(list, list_new("e"));
		list_add_back(list, list_new("v"));
		list_add_back(list, list_new("o"));
		list_add_back(list, list_new("d"));
		list_add_back(list, list_new("u"));
		list_add_back(list, list_new("p"));
		list_add_back(list, list_new("c"));
		list_add_back(list, list_new("t"));
		list_add_back(list, list_new("q"));
		list_add_back(list, list_new("b"));
		list_add_back(list, list_new("s"));
		list_add_back(list, list_new("r"));
		list_add_back(list, list_new("a"));
	}
	if (i == 4)
	{
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("1"));
	}
	if (i == 5)
	{
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("2"));
		list_add_back(list, list_new("2"));
	}
	if (i == 6)
	{
		list_add_back(list, list_new("2"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("2"));
	}
}

void	print_lists(t_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		printf("element_%d_data = %s\n", i++, (char*)list->data);
		list = list->next;
	}
}

void	ft_list_remove_if_check(t_list **list)
{
	t_list	*test;
	int		i;

	i = 1;
	printf("ft_list_remove_if\n");
	create_list(list, 1);
	test = *list;
	printf("\nOriginal list content:\n");
	print_lists(test);
	printf("\nRemove \"4\"\n");
	ft_list_remove_if(&test, "4", &ft_strcmp);
	print_lists(test);
	ft_list_clear(list);
	create_list(list, 4);
	test = *list;
	printf("\nOriginal list content:\n");
	print_lists(test);
	printf("\nRemove 1\n");
	ft_list_remove_if(&test, "1", &ft_strcmp);
	print_lists(test);
	ft_list_clear(list);
	create_list(list, 5);
	test = *list;
	printf("\nOriginal list content:\n");
	print_lists(test);
	printf("\nRemove \"1\"\n");
	ft_list_remove_if(&test, "1", &ft_strcmp);
	print_lists(test);
	ft_list_clear(list);
	create_list(list, 6);
	test = *list;
	printf("\nOriginal list content:\n");
	print_lists(test);
	printf("\nRemove \"2\"\n");
	ft_list_remove_if(&test, "2", &ft_strcmp);
	print_lists(test);
 }

void	ft_list_sort_check(t_list **list)
{
	t_list	*test;
	int		i;

	i = 1;
	printf("ft_list_sort\n");
	while (i < 4)
	{
		create_list(list, i);
		test = *list;
		printf("\nOriginal list content:\n");
		print_lists(test);
		ft_list_sort(&test, &strcmp);
		printf("\nList after ft_list_sort:\n");
		print_lists(test);
		ft_list_clear(list);
		i = i + 2;
	}
}

void	ft_list_size_check(t_list **list)
{
	t_list	*test;
	int		i;

	i = 1;
	printf("ft_list_size\n");
	while (i < 3)
	{
		create_list(list, i);
		test = *list;
		print_lists(test);
		printf("\033[0;36mList size = %d\n\n\033[0;0m", ft_list_size(test));
		i++;
	}
}

void	ft_list_push_front_check(t_list **list)
{
	t_list	*test;
	t_list	*new;

	new = malloc(sizeof(t_list));
	new->data = "NEW";
	create_list(list, 1);
	test = *list;
	printf("ft_list_push_front\n");
	printf("Original list content:\n");
	print_lists(test);
	printf("\nList after ft_list_push_front:\n");
	ft_list_push_front(&test, new->data);
	print_lists(test);
	free(test);
	free(new);
}

int		main(int argc, char **argv)
{
	t_list	*list;


	// ft_atoi_base_check();
	if (ft_strcmp(argv[1], "ft_list_push") == 0)
		ft_list_push_front_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_size") == 0)
		ft_list_size_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_sort") == 0)
		ft_list_sort_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_remove_if") == 0)
		ft_list_remove_if_check(&list);
	return (0);
}