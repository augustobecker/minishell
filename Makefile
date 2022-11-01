# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:55:32 by acesar-l          #+#    #+#              #
#    Updated: 2022/11/01 09:43:24 by gasouza          ###   ########.fr        #
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

SRCS 		= $(wildcard $(SRCS_PATH)/*.c)
OBJS 		= $(SRCS:.c=.o)

COMPILER 	= gcc -c
LINKER		= gcc
CFLAGS 		= -Wall -Wextra -Werror

CLEANUP 	= rm -rf

# To check wether lib readline is installed use:
# ldconfig -p | grep libreadline

all:		$(NAME)

$(NAME): 	$(LIBFT) $(OBJS)
			@$(LINKER) $(OBJS) -lreadline -L$(LIBFT_PATH) -lft -o $@
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c
			@$(COMPILER) -I$(INCS_PATH) $< -o $@
	
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

.PHONY:		all clean fclean re
