# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:55:32 by acesar-l          #+#    #+#              #
#    Updated: 2022/09/20 20:59:31 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

GREEN		= \033[0;32m
GREY		= \033[0;90m
RESET		= \033[0m

LIBFT_PATH	= ./libraries/Libft
LIBFT		= ./libraries/Libft/libft.a

SRCS_PATH	= ./sources

CC 			= gcc -g3

FLAGS 		=

REMOVE 		= rm -f

INCLUDES 	= -I ./includes/

SRCS 		= $(SRCS_PATH)/*.c

all:		$(NAME)

$(NAME): 	$(LIBFT)
			@$(CC) $(INCLUDES) -o $(NAME) $(SRCS) $(FLAGS) $(LIBFT)
			@echo "$(GREY)$(NAME): $(GREEN)$(NAME) was created$(RESET)"

${LIBFT}:
			@make bonus -C $(LIBFT_PATH)

clean:
			@${REMOVE} ${NAME}
			@echo "$(GREY)$(NAME): $(NAME) was deleted$(RESET)"

fclean:
			make fclean -C $(LIBFT_PATH)
			@$(REMOVE) $(NAME)
			@echo "$(GREY)$(NAME): $(NAME) was deleted$(RESET)"

re:			clean $(NAME)

.PHONY:		all clean fclean re
