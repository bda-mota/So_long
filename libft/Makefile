# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 15:55:15 by bda-mota          #+#    #+#              #
#    Updated: 2024/01/29 13:10:29 by bda-mota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libft.a
SRC_DIR	:= src
OBJ_DIR	:= obj

MAKEFLAGS	+= --silent
CC		:= cc
FLAGS	:= -Wall -Werror -Wextra
HEADER	:= -I ./src

CFILES	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			get_next_line.c get_next_line_utils.c get_next_line_bonus.c get_next_line_utils_bonus.c \
			ft_printf.c ftprint_char_functions.c ftprint_number_functions.c ftprint_hex_functions.c \
			ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_strcmp.c
SRC		:= $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(notdir $(CFILES:%.c=%.o)))

GREEN	:=	\033[1;32m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $< $(HEADER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)   [Success] Done the compilation Libft.$(BOLD) "
	@echo "$(GREEN)-------------------------------------------"


clean:
	rm -f $(OBJS)
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)  Objects - LIBFT - were cleaned!"
	@echo "$(RED)-----------------------------------"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE)  ✨ Cleaning - LIBFT - complete! ✨"
	@echo "$(RED)---------------------------------------"

re: fclean all

.PHONY: all clean fclean re bonus
