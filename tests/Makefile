# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasouza <gasouza@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 16:26:12 by gasouza           #+#    #+#              #
#    Updated: 2022/11/01 10:51:13 by gasouza          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

NAME		= Tests_Runner

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -DUNITY_FIXTURE_NO_EXTRAS
CLEANUP		= rm -rf

# Project configuration

LIBS_PATH	= ../libraries
SRCS_PATH	= ../sources
INCS_PATH	= ../includes

SRCS		= $(filter-out %minishell.c, $(wildcard $(SRCS_PATH)/*.c)) 
OBJS		= $(SRCS:.c=.o)
LIBS		= -L$(LIBS_PATH)/Libft -lft -lreadline

# Tests configuration

UNITY_PATH	= $(LIBS_PATH)/Unity

UNITY_INCS	= -I$(UNITY_PATH)/src								\
			-I$(UNITY_PATH)/extras/fixture/src					\
			
UNITY_SRCS	= $(UNITY_PATH)/extras/fixture/src/unity_fixture.c	\
			$(UNITY_PATH)/src/unity.c							\

TESTS_SRCS	= $(wildcard *.c)
TESTS_INCS	= -I$(INCS_PATH)

all: 		$(NAME) 

$(NAME): 	clean_project $(OBJS) $(TESTS_SRCS)
			@$(CC) $(CFLAGS) $(UNITY_INCS) $(TESTS_INCS) 		\
			$(OBJS) $(UNITY_SRCS) $(TESTS_SRCS) $(LIBS) -o $(NAME)
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
			@make -s -C .. $(subst ../, ,$@)

clean_project:
			@make -s -C .. clean  > /dev/null

run: 		all
			@ clear
			@ ./$(NAME)
			@ make fclean > /dev/null
			@ echo

runv: 		all
			@ clear
			@ ./$(NAME) -v
			@ make fclean > /dev/null
			@ echo

re: 		fclean all
rerun: 		re run
rerunv: 	re runv

clean: 		clean_project
			@$(CLEANUP) $(NAME)
			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
fclean:		clean

.PHONY: 	all clean_project run runv re rerun rerunv clean fclean