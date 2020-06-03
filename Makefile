# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/19 14:13:04 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/06/03 11:26:41 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s \
		ft_atoi_base.s \
		ft_list_push_front.s \
		ft_list_size.s

# BONUS = ft_atoi_base.s

OBJS = $(SRCS:.s=.o)

$(NAME): $(OBJS)
	@echo "\033[0;33m\nLibrary made\n"
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

%.o	: %.s
	nasm -f macho64 $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31mRemoved object files\033[0;29m"

test: all
	@echo "\033[0;32m\nTesting your work\n\033[0;29m"
	@gcc -Wall -Wextra -Werror -I./libasm.h libasm.a main.c -o ./libasm_test
	@./libasm_test

fclean: clean
	@rm -f $(NAME)
	@rm -f libasm_test
	@echo "\033[0;31mRemoved libasm.a"
	@echo "Removed libasm_test\033[0;31m"

re: fclean all