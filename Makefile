# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 20:55:32 by acesar-l          #+#    #+#              #
#    Updated: 2022/12/09 18:28:50 by gnuncio-         ###   ########.fr        #
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

SRCS 		=	./sources/builtins/cd.c									\
				./sources/builtins/echo.c								\
				./sources/builtins/env.c								\
				./sources/builtins/export.c								\
				./sources/builtins/is_a_builtin.c						\
				./sources/builtins/minishell_exit.c						\
				./sources/builtins/pwd.c								\
				./sources/builtins/unset.c								\
				./sources/cmd/cmd_create_list.c							\
				./sources/cmd/cmd_parse_str.c							\
				./sources/envp/expand_vars.c							\
				./sources/envp/get_env_value.c							\
				./sources/envp/get_var_name.c							\
				./sources/envp/get_var_value.c							\
				./sources/envp/set_env_value.c							\
				./sources/envp/unset_env_value.c						\
				./sources/error/error.c									\
				./sources/execution/execute_builtin.c					\
				./sources/execution/execution.c							\
				./sources/execution/execution_clear.c					\
				./sources/execution/execution_exit.c					\
				./sources/execution/execution_utils.c					\
				./sources/execution/save_last_exit_code.c				\
				./sources/files/files_manager.c							\
				./sources/lexical/get_infile_token.c					\
				./sources/lexical/get_next_token.c						\
				./sources/lexical/get_outfile_token.c					\
				./sources/lexical/get_string_double_quotes_token.c		\
				./sources/lexical/get_string_single_quotes_token.c		\
				./sources/lexical/get_string_unquoted_token.c			\
				./sources/lexical/is_infile_token.c						\
				./sources/lexical/is_outfile_token.c					\
				./sources/lexical/is_string_token.c						\
				./sources/lexical/is_valid_expand_vars_token.c			\
				./sources/lexical/token_create.c						\
				./sources/lexical/token_destroy.c						\
				./sources/lexical/token_to_str.c						\
				./sources/memory_clears/clear_history.c					\
				./sources/memory_clears/clear_memory.c					\
				./sources/memory_clears/dead_minihell.c					\
				./sources/minishell/minishell_create.c					\
				./sources/minishell/minishell_init.c					\
				./sources/signals/signals.c								\
				./sources/syntax/parse_pipe.c							\
				./sources/syntax/syntax.c								\
				./sources/syntax/tokenization.c							\
				./sources/types/cmd_create.c							\
				./sources/types/cmd_destroy.c							\
				./sources/types/file_create.c							\
				./sources/types/file_destroy.c							\
				./sources/utils/array_append.c							\
				./sources/utils/array_destroy.c							\
				./sources/utils/array_dup.c								\
				./sources/utils/array_print.c							\
				./sources/utils/array_size.c							\
				./sources/utils/ft_strcmp.c								\
				./sources/utils/global_manager.c						\
				./sources/utils/stack_utils.c							\
				./sources/minishell.c									\
				./sources/prompt.c

OBJS 		= $(SRCS:.c=.o)

COMPILER 	= gcc -g -c
LINKER		= gcc
CFLAGS 		= -Wall -Wextra -Werror

CLEANUP 	= rm -rf

all:		$(NAME)

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

.PHONY:		all clean fclean re
