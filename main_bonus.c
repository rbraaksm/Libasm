/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/08 09:41:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/10 13:06:39 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_bonus.h"
#include <stdio.h>

static int	ft_is_in_base(const char *str, const char *base)
{
	const char	*head;
	const char	*str_head;

	head = base;
	str_head = str;
	while (*str)
	{
		while (*base)
		{
			if (*str == *base)
				break ;
			++base;
			if (!(*base) && str == str_head)
				return (0);
		}
		base = head;
		++str;
	}
	return (1);
}

static int	ft_is_base_valid2(const char *str, const char *base)
{
	const char	*head;
	const char	*iter;

	head = base;
	iter = base;
	while (*iter)
	{
		if (!(*iter) || *iter == '+' || *iter == '-'
				|| *iter < ' ' || *iter == 127)
			return (0);
		base = iter + 1;
		while (*base)
		{
			if (*base == *iter)
				return (0);
			++base;
		}
		++iter;
	}
	if (!ft_is_in_base(str, head))
		return (0);
	return (1);
}

static long	ft_get_base_size2(const char *base)
{
	int	size;

	size = 0;
	while (*base)
	{
		++base;
		++size;
	}
	return (size);
}

static int	ft_get_num(const char c, const char *base)
{
	int	i;

	i = 0;
	while (c != *base && *base)
	{
		++i;
		++base;
	}
	return (i);
}

int			ft_atoi_base_test(const char *str, const char *base)
{
	int		signal;
	long	num;
	int		size;

	num = 0;
	signal = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal *= -1;
		++str;
	}
	if (!ft_is_base_valid2(str, base))
		return (0);
	size = ft_get_base_size2(base);
	while (ft_get_num(*str, base) == size)
		++str;
	while (*str && ft_get_num(*str, base) != size)
	{
		num *= size;
		num += ft_get_num(*str, base);
		++str;
	}
	num *= signal;
	return (num);
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
	}
	if (i == 5)
	{
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("2"));
		list_add_back(list, list_new("2"));
		list_add_back(list, list_new("1"));
		list_add_back(list, list_new("1"));
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
	printf("\nRemove \"1\"\n");
	ft_list_remove_if(&test, "1", &ft_strcmp);
	print_lists(test);
	ft_list_clear(list);
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
	ft_list_clear(list);
	test = *list;
	printf("\nOriginal list content:\n");
	print_lists(test);
	printf("\nList after ft_list_push_front:\n");
	ft_list_push_front(&test, new->data);
	print_lists(test);
	free(new);
}

void	ft_atoi_base_check()
{
	printf("\n--ft_atoi_base\n");
	printf("Mine = %d\n", ft_atoi_base("42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("0", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("0", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("1", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("1", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("1215415478", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("1215415478", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-0", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-0", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-1", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-1", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("--42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("--42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-+-42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-+-42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-+-+-+42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-+-+-+42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-+-+-+-42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-+-+-+-42", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-1215415478", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-1215415478", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("2147483647", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("2147483648", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("2147483648", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-2147483648", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-2147483649", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-2147483649", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("2a", "0123456789abcdef"));
	printf("Real = %d\n\n", ft_atoi_base_test("2a", "0123456789abcdef"));
	printf("Mine = %d\n", ft_atoi_base("ff", "0123456789abcdef"));
	printf("Real = %d\n\n", ft_atoi_base_test("ff", "0123456789abcdef"));
	printf("Mine = %d\n", ft_atoi_base("poney", "poney"));
	printf("Real = %d\n\n", ft_atoi_base_test("poney", "poney"));
	printf("Mine = %d\n", ft_atoi_base("dommage", "invalid"));
	printf("Real = %d\n\n", ft_atoi_base_test("dommage", "invalid"));
	printf("Mine = %d\n", ft_atoi_base("dommage", "aussi invalide"));
	printf("Real = %d\n\n", ft_atoi_base_test("dommage", "aussi invalide"));
	printf("Mine = %d\n", ft_atoi_base("dommage", "+toujours"));
	printf("Real = %d\n\n", ft_atoi_base_test("dommage", "+toujours"));
	printf("Mine = %d\n", ft_atoi_base("42FINIS !", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("42FINIS !", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("-42FINIS !", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("-42FINIS !", "0123456789"));
	printf("Mine = %d\n", ft_atoi_base("C'est dommage42", "0123456789"));
	printf("Real = %d\n\n", ft_atoi_base_test("C'est dommage42", "0123456789"));
}

int		main(int argc, char **argv)
{
	t_list	*list;

	if (ft_strcmp(argv[1], "ft_atoi_base") == 0)
		ft_atoi_base_check();
	else if (ft_strcmp(argv[1], "ft_list_push_front") == 0)
		ft_list_push_front_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_size") == 0)
		ft_list_size_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_sort") == 0)
		ft_list_sort_check(&list);
	else if (ft_strcmp(argv[1], "ft_list_remove_if") == 0)
		ft_list_remove_if_check(&list);
	return (0);
}