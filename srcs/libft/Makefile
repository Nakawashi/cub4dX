# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 14:02:05 by lgenevey          #+#    #+#              #
#    Updated: 2022/12/30 18:10:22 by lgenevey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_free_ppointer.c \
		get_next_line.c \
		get_next_line_utils.c \

SRCS_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstadd_back.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

BLUE	= \033[0;34m
GREEN	= \033[0;32m
NONE	= \033[0m

%.o: %.c
	@printf "$(YELLOW)Compiling $(BOLD)%-100s \r" $<
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

both: $(NAME) bonus

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@printf "$(GREEN) $(NAME) ready.\n$(NONE)"

bonus: $(OBJS_BONUS) $(OBJS)
	@ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	@printf "$(GREEN) $(NAME) bonus ready.\n$(NONE)"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	@rm -f  $(NAME)
	@printf "$(BLUE) $(NAME) cleaned.\n$(NONE)"

re: fclean all

.PHONY: all bonus clean fclean re
.SILENT: $(NAME) all clean fclean re
