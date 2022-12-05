# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:55:32 by acesar-l          #+#    #+#              #
#    Updated: 2022/12/05 09:50:05 by gnuncio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		= minishell

INCS_PATH 	= ./includes
LIBS_PATH	= ./libraries
SRCS_PATH	= ./sources

LIBFT_PATH	= $(LIBS_PATH)/Libft
LIBFT		= $(LIBFT_PATH)/libft.a

SRCS 		= $(wildcard $(SRCS_PATH)/*.c) $(wildcard $(SRCS_PATH)/*/*.c)
OBJS 		= $(SRCS:.c=.o)

COMPILER 	= gcc -g -c
LINKER		= gcc
# CFLAGS 		= -Wall -Wextra -Werror

CLEANUP 	= rm -rf

# To check wether lib readline is installed use:
# ldconfig -p | grep libreadline

all:		$(NAME)
teste:
	@echo $(OBJS)

$(NAME): 	$(LIBFT) $(OBJS)
			@$(LINKER) $(CFLAGS) $(OBJS) -lreadline -L$(LIBFT_PATH) -lft -o $@
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c
			@$(COMPILER) $(CFLAGS) -I$(INCS_PATH) $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)

clean:
			@$(CLEANUP) $(OBJS)
			@echo "$(NAME): $(RED)object files were deleted$(RESET)"
			@make -s -C $(LIBFT_PATH) clean

fclean: 	clean
			@$(CLEANUP) $(NAME)
			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
			@make -s -C $(LIBFT_PATH) fclean

re:			fclean $(NAME)

tests:
			@make -s -C tests run

testsv:
			@make -s -C tests runv

val: all
			valgrind --suppressions=./local.supp --leak-check=full ./minishell

val2: all
			valgrind --suppressions=./local.supp --leak-check=full --track-origins=yes --show-leak-kinds=all ./minishell

.PHONY:		all clean fclean re tests testsv val
