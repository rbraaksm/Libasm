# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/19 14:13:04 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/06/08 17:46:31 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s \

BONUS = ft_atoi_base_bonus.s \
		ft_list_push_front_bonus.s \
		ft_list_size_bonus.s \
		ft_list_sort_bonus.s \
		ft_list_remove_if_bonus.s \
		ft_list_remove_if_bonus2.s

OBJ = $(SRCS:.s=.o)

B_OBJ = $(SRCS:.s=.o) $(BONUS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mUpdating library..."
	ar rc $(NAME) $^
	ranlib $(NAME)
	rm -f $(OBJ)
	rm -f $(B_OBJS)
	@echo "\033[0m"

%.o: %.s
	@echo "\033[0;32mGenerating binary..."
	nasm -f macho64 $< -o $@
	@echo "\033[0m"

clean:
	@echo "\033[0;31mCleaning..."
	rm -f ./test
	rm -f ./test_bonus
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31mRemoving library..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

bonus: $(B_OBJ)
	@echo "\033[0;33mUpdating library (with bonuses)..."
	ar rc $(NAME) $^
	ranlib $(NAME)
	rm -f $(B_OBJ)
	@echo "\033[0m"

test: re
	@echo "\033[0;36mTesting : "
	gcc -L. -lasm -o test main.c
	@echo "\033[0m"
	./test

test_bonus: $(B_OBJ)
	@echo "\033[0;33mUpdating library (with bonuses)..."
	ar rc $(NAME) $^
	ranlib $(NAME)
	rm -f $(B_OBJ)
	rm -f $(OBJ)
	@echo "\033[0m"
	@echo "\033[0m"
	@echo "\033[0;36mTesting : "
	gcc -L. -lasm -o test_bonus main_bonus.c
	@echo "\033[0m"
	./test_bonus