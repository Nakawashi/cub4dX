# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:24:51 by lgenevey          #+#    #+#              #
#    Updated: 2023/02/06 11:52:29 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

#################################
#								#
#			COULEURS			#
#								#
#################################
BLUE	= \033[0;34m
VIOLET	= \033[0;36m
GREEN	= \033[0;32m
RED		= \033[0;31m
YELLOW	= \033[0;33m
NONE	= \033[0m

#################################
#								#
#			SOURCES				#
#								#
#################################
SRCS_FILES	=	srcs/main.c \
				srcs/general/display_background.c \
				srcs/general/init_interface.c \
				srcs/general/quit.c \
				srcs/map/read_map.c \
				srcs/map/check_map_utils.c \
				srcs/map/read_file.c \
				srcs/map/read_args.c \
				srcs/map/parse_utils.c \
				srcs/map/parse_color.c \
				srcs/utils/img_utils.c \
				srcs/utils/maths_utils.c \
				srcs/utils/bresenham.c \
				srcs/minimap/create_square.c \
				srcs/minimap/init_minimap.c \
				srcs/hooks/events.c \
				srcs/player/init_player.c \
				srcs/render/draw.c \
				srcs/dda/dda.c \
				srcs/dda/dda_utils.c \

#####################################
#									#
#			COMPILATION				#
#									#
#####################################
CC			= gcc
rm			= rm -rf
OBJS		= $(SRCS_FILES:.c=.o)
CFLAGS		= -Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address -g3
endif

#####################################
#									#
#		REPERTOIRES, OPTIONS		#
#									#
#####################################
# DIR_OBJS	= objs/
DIR_HEADER	= incs/
DIR_LIBFT	= srcs/libft
DIR_MLX		= srcs/minilibx
OPTIONS 	:= -I$(DIR_MLX)
OPTIONS		+= -I$(DIR_LIBFT)
OPTIONS		+= -I$(DIR_HEADER)
CFLAGS		+= $(OPTIONS)

INCLUDES	:= -framework OpenGL -framework AppKit
INCLUDES	+= -L $(DIR_LIBFT) -lft
INCLUDES	+= -L $(DIR_MLX) -lmlx


all: $(NAME)

$(OBJS): %.o : %.c incs/cub3d.h
	$(CC) $(CFLAGS) -I $(OPTIONS) -o $@ -c $<

$(NAME):	$(OBJS)
	@printf "$(BLUE)Making libmlx... $(NONE)"
	@$(MAKE) -C $(DIR_MLX)
	@printf "$(BLUE)Making libft... $(NONE)"
	@$(MAKE) both -C $(DIR_LIBFT)
	@printf "$(BLUE)Making CUB3D... $(NONE)"
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(INCLUDES)
	@printf "$(GREEN) CUB3D ready.\n$(NONE)"

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_MLX) clean
	@printf "$(GREEN) OBJS removed in cub3D, libft and libmlx.\n$(NONE)"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(GREEN) $(NAME) removed.\n$(NONE)"
	@$(MAKE) -C $(DIR_LIBFT) fclean
	@printf "$(GREEN) libft.a removed.\n$(NONE)"
	@$(MAKE) -C $(DIR_MLX) clean
	@printf "$(GREEN) libmlx.a removed.\n$(NONE)"

re: fclean all

.PHONY: all clean fclean re