# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 17:02:42 by acesar-l          #+#    #+#              #
#    Updated: 2022/08/20 09:20:04 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

GREEN		= \033[0;32m
GREY		= \033[0;90m
RED			= \033[0;31m
RESET		= \033[0m

CC 			= clang

FLAGS 		= -Wall -Werror -Wextra

REMOVE 		= rm -f

SRCS 		= ft_isalpha.c 					\
			ft_isdigit.c 					\
			ft_isalnum.c 					\
			ft_isascii.c 					\
			ft_isprint.c 					\
			ft_strlen.c 					\
			ft_memset.c 					\
			ft_bzero.c 						\
			ft_memcpy.c 					\
			ft_memmove.c 					\
			ft_strlcpy.c 					\
			ft_strlcat.c 					\
			ft_toupper.c 					\
			ft_tolower.c 					\
			ft_strchr.c 					\
			ft_strrchr.c 					\
			ft_strncmp.c					\
			ft_memchr.c						\
			ft_memcmp.c						\
			ft_strnstr.c					\
			ft_atoi.c 						\
			ft_strdup.c 					\
			ft_calloc.c 					\
			ft_strnstr.c 					\
			ft_itoa.c 						\
			ft_substr.c	 					\
			ft_split.c 						\
			ft_strjoin.c 					\
			ft_strtrim.c					\
			ft_itoa.c 						\
			ft_strmapi.c 					\
			ft_striteri.c 					\
			ft_putchar_fd.c 				\
			ft_putstr_fd.c 					\
			ft_putendl_fd.c 				\
			ft_putnbr_fd.c					\
			ft_count_occurrences.c			\
			ft_free_str_array.c				\
			ft_strappend.c					\
			get_next_line/get_next_line.c	\
			ft_printf/ft_printf.c			\
			ft_printf/ft_argument_c.c		\
			ft_printf/ft_arguments_d_i.c	\
			ft_printf/ft_argument_p.c		\
			ft_printf/ft_argument_percent.c	\
			ft_printf/ft_argument_s.c		\
			ft_printf/ft_argument_u.c		\
			ft_printf/ft_arguments_x.c		\
			ft_printf/ft_free_ptr.c			\
			ft_printf/ft_hex_length.c		\
			ft_printf/ft_decimal_length.c	\
			ft_printf/ft_print_reversed_str.c	\
			ft_printf/ft_decimal_converter_to_hex.c

BONUS_SRCS  	= ft_lstnew.c			\
			ft_lstadd_front.c			\
			ft_lstsize.c				\
			ft_lstlast.c				\
			ft_lstadd_back.c			\
			ft_lstdelone.c				\
			ft_lstclear.c				\
			ft_lstiter.c				\
			ft_lstmap.c

OBJS 		= $(SRCS:.c=.o)

BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

all:		${NAME}

${NAME}: 	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@echo "$(GREY)Libft: $(GREEN)$(NAME) was created$(RESET)"

bonus:		${NAME} ${BONUS_OBJS}
			@ar -rcs ${NAME} ${BONUS_OBJS}
			@echo "$(GREY)Libft: $(GREEN)$(NAME) was created with Bonus$(RESET)"

.c.o:
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
			@${REMOVE} ${OBJS} ${BONUS_OBJS}
			@echo "$(GREY)Libft: object files were deleted$(RESET)"

fclean:		clean
			@${REMOVE} ${NAME}
			@echo "$(GREY)Libft: $(NAME) was deleted$(RESET)"

re:			fclean ${NAME}

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
