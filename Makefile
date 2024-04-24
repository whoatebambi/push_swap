# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 18:59:07 by fcouserg          #+#    #+#              #
#    Updated: 2023/11/23 17:46:38 by fcouserg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = push_swap_bonus

CC = cc
CFLAGS = -g ##-Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = libft/
INC_DIR = inc/
SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
OBJ_DIR = obj/

SRC = main.c  parsing_error_handling.c parsing.c lst_utils.c sorting.c sorting_init_a.c sorting_init_b.c sorting_push.c commands_swap.c commands_rotate.c commands_rev_rotate.c commands_push.c
# SRC = commands.c ft_split.c parsing.c push_swap.c stack_utils.c
SRC_BONUS = commands_bonus.c ft_split_bonus.c parsing_bonus.c push_swap_bonus.c stack_utils_bonus.c
# SRC = $(SRC_DIR)/commands.c $(SRC_DIR)/ft_split.c $(SRC_DIR)/parsing.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/stack_utils.c
# SRC_BONUS = $(SRC_BONUS_DIR)/commands.c $(SRC_DIR)/ft_split.c $(SRC_DIR)/parsing.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/stack_utils.c

SRC_NAMES	= $(SRC)
SRC_NAMES_BONUS = $(SRC_BONUS)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_BONUS:.c=.o)))


# # ...
# TESTERS_DIR = testers/42Barcelona-PushSwap-ProChecker

# $(TESTERS_DIR)/$(NAME): $(OBJ)
# 	@make -C $(LIBFT_DIR)
# 	@$(CC) $(CFLAGS) -o $(TESTERS_DIR)/$(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -I$(INC_DIR)
# 	@echo "\033[0;92m* push_swap file was created in $(TESTERS_DIR) *\033[0m"


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft -I$(INC_DIR)
	@echo "\033[0;92m* file was created *\033[0m"

bonus: $(OBJ_BONUS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -I$(INC_DIR)
	@echo "\033[0;92m* bonus file was created *\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;91m* object files were deleted *\033[0m"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f push_swap push_swap_bonus
	@echo "\033[0;91m* all files were deleted *\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re



# SRCS	=	push_swap.c split.c \

# OBJS	=	$(SRCS:.c=.o)

# CC		=	gcc
# CFLAGS	=	-Wall -Wextra -Werror -I.
# NAME	=	push_swap

# all:		$(NAME)

# $(NAME):	$(OBJS)
# 			ar rcs $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

# clean:
# 			rm -f $(OBJS)

# fclean:		clean
# 			rm -f $(NAME)

# re:			fclean all

# .PHONY:		all clean fclean re
