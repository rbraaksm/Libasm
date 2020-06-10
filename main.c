/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/19 14:38:45 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/06/10 13:02:12 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>

void	ft_strdup_check(void)
{
	char	*src;
	int		i;

	i = 0;
	printf("\033[0;33m>>>>>>>> FT_STRDUP <<<<<<<<\n\n");
	while (i < 4)
	{
		i == 0 ? src = "Codam is fun." : 0;
		i == 1 ? src = "" : 0;
		i == 2 ? src = "\n" : 0;
		i == 3 ? src = "aklmnopqrstuvwxyz" : 0;
		printf("\033[0;29m----------------\nSrc = %s\n", src);
		strcmp(ft_strdup(src), strdup(src)) != 0 ?
		printf("\033[0;33mNOT CORRECT\n") : printf("\033[0;32mCORRECT\n");
		printf("\033[0;29m----------------\n");
		i++;
	}
	printf("\033[0;29m----------------\nSrc = %s\n", NULL);
	src = ft_strdup(NULL);
	printf("\033[0;32mCORRECT, it will not segfault \n");
	printf("\033[0;29m----------------\n");
}

void	ft_read_check()
{
	int fd;
	char uni_buf[50];
	char lib_buf[50];
	ssize_t ret;

	printf("\033[0;33m>>>>>>>> FT_READ <<<<<<<<\n\n");
	printf("\033[0;29m---------------------------------\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, uni_buf, 5);
	printf("Real : %zd\n", ret);
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, lib_buf, 5);
	printf("Mine : %zd\n", ret);
	close(fd);
	printf("---------------------------------\n");
	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = read(fd, uni_buf, 5);
	printf("Real : %zd\n", ret);
	close(fd);
	fd = open("emptyFile", O_RDONLY | O_CREAT | O_TRUNC, 0777);
	ret = ft_read(fd, lib_buf, 5);
	printf("Mine : %zd\n", ret);
	close(fd);
	remove("emptyFile");
	errno = 0;
	printf("---------------------------------\n");
	fd = open("I don't exist", O_RDONLY);
	ret = read(fd, uni_buf, 5);
	printf("Real return : %zd\n", ret);
	perror("Real errno ");
	close(fd);
	errno = 0;
	fd = open("I don't exist", O_RDONLY);
	ret = ft_read(fd, lib_buf, 5);
	printf("Mine return : %zd\n", ret);
	perror("Mine errno ");
	close(fd);
	errno = 0;
	printf("---------------------------------\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, NULL, 5);
	printf("Real return : %zd\n", ret);
	perror("Real errno ");
	close(fd);
	errno = 0;
	fd = open("Makefile", O_RDONLY);
	ret = ft_read(fd, NULL, 5);
	printf("Mine return : %zd\n", ret);
	perror("Mine errno ");
	close(fd);
	printf("---------------------------------\n\n");
}

void	ft_write_check()
{
	int a;
	int b;

	printf("\033[0;33m>>>>>>>> FT_WRITE <<<<<<<<\n\n");
	printf("\033[0;29m---------------------------------\n");
	a = write(-40 + 1, "Codam is fun\n", 14);
	perror("\033[0;29mReal errno ");
	errno = 0;
	b = ft_write(-40 + 1, "Codam is fun\n", 14);
	perror("Mine errno ");
	printf("Real return : %d\nMine return : %d\n", a, b);
	printf("\033[0;29m---------------------------------\n");
	a = write(1, NULL, 9);
	perror("Real errno ");
	errno = 0;
	b = ft_write(1, NULL, 9);
	perror("Mine errno ");
	printf("Real return : %d\nMine return : %d\n", a, b);
	printf("\033[0;29m---------------------------------\n");
	a = write(1, 0, 10);
	perror("Real errno ");
	errno = 0;
	b = ft_write(1, 0, 10);
	perror("Mine errno ");
	printf("Real return : %d\nMine return : %d\n", a, b);
	printf("\033[0;29m---------------------------------\n");
	a = write(40, "hello", 5);
	perror("Real errno ");
	errno = 0;
	b = ft_write(40, "hello", 5);
	perror("Mine errno ");
	printf("Real return : %d\nMine return : %d\n", a, b);
	printf("\033[0;29m---------------------------------\n\n");
}

void	ft_strcmp_check(void)
{
	char			*src;
	char			*dst;
	int				i;

	i = 0;
	printf("\033[0;33m>>>>>>>> FT_STRCMP <<<<<<<<\n\n");
	while (i < 4)
	{
		i == 0 ? src = "Codam is fun." : 0;
		i == 0 ? dst = "Codam is fun." : 0;
		i == 1 ? src = "" : 0;
		i == 1 ? dst = "hoi" : 0;
		i == 2 ? src = "\n" : 0;
		i == 2 ? dst = "\n\n" : 0;
		i == 3 ? src = "aklmnopqrstuvwxyz" : 0;
		i == 3 ? dst = "abcdefghijklmnopqrstuvwxyz" : 0;
		printf("\033[0;29m----------------\nSrc = %s\nDst = %s\n", src, dst);
		((strcmp(src, dst)) != (ft_strcmp(src, dst))) != 0 ?
		printf("\033[0;33mNOT CORRECT\n") : printf("\033[0;32mCORRECT\n");
		printf("\033[0;29m----------------\n");
		i++;
	}
	printf("\033[0;29m----------------\nInput:\nDst = \033[0;34mNULL\n\033[0;29msrc = \033[0;34mNULL\n");
	ft_strcmp(NULL, NULL);
	printf("\033[0;32mCORRECT, it will not segfault \n");
	printf("\033[0;29m----------------\n\n");
}

void	ft_strcpy_check(void)
{
	char			*src;
	char			dst[30];
	int				i;

	i = 0;
	printf("\n\033[0;33m>>>>>>>> FT_STRCPY <<<<<<<<\n\n");
	while (i < 4)
	{
		i == 0 ? src = "Codam is fun." : 0;
		i == 1 ? src = "" : 0;
		i == 2 ? src = "\n" : 0;
		i == 3 ? src = "abcdefghijklmnopqrstuvwxyz" : 0;
		printf("\033[0;29m----------------\nString = %s\n", src);
		strcmp(src, ft_strcpy(dst, src)) != 0 ?
		printf("\033[0;33mNOT CORRECT\n") : printf("\033[0;32mCORRECT\n");
		printf("\033[0;29m----------------\n");
		i++;
	}
	printf("\033[0;29m----------------\nInput:\nDst = \033[0;34mNULL\n\033[0;29msrc = Hi !!\n");
	ft_strcpy(NULL, "Hi !!");
	printf("\033[0;32mCORRECT, it will not segfault \n");
	printf("\033[0;29m----------------\n");
	printf("\033[0;29m----------------\nInput:\nDst = \033[0;29mHi !!\nsrc = \033[0;34mNULL\n");
	ft_strcpy("Hi !!", NULL);
	printf("\033[0;32mCORRECT, it will not segfault \n");
	printf("\033[0;29m----------------\n\n");
}

void	ft_strlen_check(void)
{
	char			*str;
	int				i;

	i = 0;
	printf("\033[0;33m>>>>>>>> FT_STRLEN <<<<<<<<\n\n");
	while (i < 4)
	{
		i == 0 ? str = "Codam is fun." : 0;
		i == 1 ? str = "" : 0;
		i == 2 ? str = "\n" : 0;
		i == 3 ? str = "abcdefghijklmnopqrstuvwxyz" : 0;
		printf("\033[0;29m----------------\nString = %s\n", str);
		((strlen(str)) - (ft_strlen(str))) != 0 ?
		printf("\033[0;33mNOT CORRECT\n") : printf("\033[0;32mCORRECT\n");
		printf("\033[0;29m----------------\n");
		i++;
	}
	str = NULL;
	printf("\033[0;29m----------------\nString = %s\n", str);
	ft_strlen(str);
	printf("\033[0;32mCORRECT, it will not segfault \n");
	printf("\033[0;29m----------------\n");
}

int		main(int arg, char **argv)
{
	if (ft_strcmp(argv[1], "ft_strlen") == 0)
		ft_strlen_check();
	else if (ft_strcmp(argv[1], "ft_strcpy") == 0)
		ft_strcpy_check();
	else if (ft_strcmp(argv[1], "ft_strcmp") == 0)
		ft_strcmp_check();
	else if (ft_strcmp(argv[1], "ft_write") == 0)
		ft_write_check();
	else if (ft_strcmp(argv[1], "ft_read") == 0)
		ft_read_check();
	else if (ft_strcmp(argv[1], "ft_strdup") == 0)
		ft_strdup_check();
	return (0);
}
