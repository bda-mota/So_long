# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 12:13:52 by bda-mota          #+#    #+#              #
#    Updated: 2024/02/19 13:19:53 by bda-mota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
NAME_BONUS	:= so_long_bonus
CFLAGS		:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

# LIBRARIES_PATH
LIBMLX	:= ./MLX42
LIBFT_PATH = ./libft
LIBFT = $(addprefix $(LIBFT_PATH)/, libft.a)

# PATHS
CC			:= gcc
SRC_PATH 	:= sources
OBJ_PATH 	:= objects
BONUS_PATH	:= sources_bonus
OBONUS_PATH	:= objects_bonus

# SOURCES
CFILES		:= 0_ft_init.c 1_ft_check.c 2_ft_validate_utils.c \
			3_ft_matrix.c 4_ft_flood.c 5_start_game.c 7_put_images.c \
			6_build_images.c 8_movements.c 10_finish_game.c 9_upt_images.c

CBONUS		:=  0_ft_init_bonus.c 1_ft_check_bonus.c 2_ft_validate_utils_bonus.c 3_ft_matrix_bonus.c \
			4_ft_flood_bonus.c 5_start_game_bonus.c 6_build_images_bonus.c 7_put_images_bonus.c \
			8_movements_bonus.c 9_upt_images_bonus.c 10_finish_game_bonus.c 11_count_steps_bonus.c 12_animation_bonus.c

SRCS		:= $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS		:= $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))
SRC_BONUS	:= $(addprefix $(BONUS_PATH)/, $(CBONUS))
OBJ_BONUS	:= $(addprefix $(OBONUS_PATH)/, $(CBONUS:%.c=%.o))

HEADERS		:= -I ./include -I $(LIBMLX)/include
HEADER_FILE := include/so_long.h include/so_long_bonus.h
LIBS_MLX	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

MAKEFLAGS += --silent

# COLORS
GREEN	:=	\033[1;32m
PURPLE	:=	\033[1;35m
RED		:=	\033[1;31m
WHITE	:=	\033[1;37m
BOLD	:=	\033[1;1m

all: libmlx $(OBJ_PATH) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

bonus: libmlx libft $(NAME_BONUS)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(HEADER_FILE) | $(OBONUS_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBONUS_PATH):
	@mkdir -p $(OBONUS_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBS_MLX) $(LIBFT) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)SO LONG$(WHITE)] has been compiled!  "
	@echo "$(GREEN)-------------------------------------------"

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBS_MLX) $(LIBFT) $(INCLUDES) -o $(NAME_BONUS)
	@echo "$(GREEN)----------------------------------------------"
	@echo "$(WHITE)     The [$(PURPLE)SO LONG BONUS$(WHITE)] has been compiled!  "
	@echo "$(GREEN)----------------------------------------------"

clean:
	@rm -rf $(OBJS) $(OBONUS_PATH)
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE) Objects - SO_LONG - were cleaned!"
	@echo "$(RED)-----------------------------------"

fclean: clean
	@echo "$(RED)-----------------------------------"
	@echo "$(WHITE)        Cleaning all... 🧹"
	@echo "$(RED)-----------------------------------"
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo "$(RED)---------------------------------------"
	@echo "$(WHITE) ✨ Cleaning - SO_LONG - complete! ✨"
	@echo "$(RED)---------------------------------------"

re: clean all

.PHONY: all, clean, fclean, re, libmlx
