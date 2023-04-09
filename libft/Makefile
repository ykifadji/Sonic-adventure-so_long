# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:59:43 by ykifadji          #+#    #+#              #
#    Updated: 2023/03/04 16:39:38 by ykifadji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH = ./libft/
SRCS_LIBFT = $(addprefix $(LIBFT_PATH), ft_bzero.c \
									ft_isalnum.c \
									ft_isascii.c \
									ft_isprint.c \
									ft_strlen.c \
									ft_toupper.c \
									ft_isalpha.c \
									ft_isdigit.c \
									ft_memset.c \
									ft_tolower.c \
									ft_strlcpy.c \
									ft_strlcat.c \
									ft_memcpy.c \
									ft_memmove.c \
									ft_atoi.c \
									ft_strchr.c \
									ft_strrchr.c \
									ft_strdup.c \
									ft_strncmp.c \
									ft_memcmp.c \
									ft_memchr.c \
									ft_calloc.c \
									ft_strnstr.c \
									ft_putchar_fd.c \
									ft_putstr_fd.c \
									ft_putendl_fd.c \
									ft_putnbr_fd.c \
									ft_substr.c \
									ft_strjoin.c \
									ft_strtrim.c \
									ft_strmapi.c \
									ft_striteri.c \
									ft_split.c \
									ft_itoa.c \
									ft_lstnew.c \
									ft_lstadd_back.c \
									ft_lstsize.c \
									ft_lstlast.c \
									ft_lstadd_front.c \
									ft_lstdelone.c \
									ft_lstiter.c \
									ft_lstclear.c \
									ft_lstmap.c)

FT_PRINTF_PATH = ./ft_printf/
SRCS_FT_PRINTF = $(addprefix $(FT_PRINTF_PATH), ft_char.c \
												ft_nbr.c \
												ft_printf.c)

GNL_PATH = ./get_next_line/
SRCS_GNL = $(addprefix $(GNL_PATH), get_next_line.c \
									get_next_line_utils.c)

OBJS = $(SRCS_LIBFT:.c=.o) $(SRCS_FT_PRINTF:.c=.o) $(SRCS_GNL:.c=.o)

NAME = libft.a
all : $(NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	@$(CC) $(CFLAGS) -c -I ./inc $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re