# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:24:51 by lgenevey          #+#    #+#              #
#    Updated: 2022/12/30 16:17:42 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D


BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m


SRCS_FILES	=	srcs/main.c \
				srcs/general/init_window.c \
				srcs/general/quit.c \


CFLAGS		= -Wall -Wextra -Werror
#DEBUG		= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g3
endif
CC			= gcc
rm			= rm -rf
OBJS		= $(SRCS_FILES:.c=.o)


DIR_OBJS	= objs/
DIR_HEADER	= incs/cub3d.h
DIR_LIBFT	= libft/
DIR_MLX		= minilibx/
OPTIONS 	:= -I$(DIR_MLX)

LIBS		:= -L$(DIR_LIBFT) -lft
LIBS		+= -L$(DIR_MLX) -lmlx
INCLUDES	:= -framework OpenGL -framework AppKit
INCLUDES	+= -L $(DIR_LIBFT) -lft -L $(DIR_MLX) -lmlx


all: $(NAME)

$(NAME):	$(OBJS)
	@echo "$(BLUE)Making libmlx... $(NONE)"
	@$(MAKE) -C $(DIR_MLX)
	@echo "$(BLUE)Making libft... $(NONE)"
	@$(MAKE) -C $(DIR_LIBFT)
	@echo "$(BLUE)Making so_long... $(NONE)"
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(DEBUG) $(LIBS) $(INCLUDES)
	@echo "$(GREEN) so_long ready.\n$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_MLX) clean
	@echo "$(GREEN) OBJS removed in cub3D, libft and libmlx.\n$(NONE)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) $(NAME) removed.\n$(NONE)"
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@echo "$(GREEN) libft.a removed.\n$(NONE)"
	@$(MAKE) -C $(DIR_MLX) clean
	@echo "$(GREEN) libmlx.a removed.\n$(NONE)"

re: fclean all

.PHONY: all clean fclean re