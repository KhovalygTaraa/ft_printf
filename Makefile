# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swquinc <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 13:12:27 by swquinc           #+#    #+#              #
#    Updated: 2021/06/09 10:24:36 by swquinc          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_TMP = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_split.c ft_memccpy.c ft_memchr.c ft_putchar_fd.c \
ft_itoa.c ft_memcmp.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strchr.c ft_strdup.c ft_strlen.c ft_putendl_fd.c \
ft_strlcpy.c ft_strjoin.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_strlcat.c \
ft_tolower.c ft_toupper.c ft_memmove.c ft_substr.c \
ft_memset.c ft_memcpy.c ft_uitoa.c ft_salloc.c 

PRINTF = ptf_flags.c ptf_flags2.c ft_printf.c \
ptf_1types.c ptf_2types.c ptf_3types.c

OBJS = ft_atoi.o ft_bzero.o ft_memcpy.o ft_memset.o \
ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
ft_split.o ft_memccpy.o ft_memchr.o ft_putchar_fd.o \
ft_itoa.o ft_memcmp.o ft_putnbr_fd.o ft_putstr_fd.o \
ft_strchr.o ft_strdup.o ft_strlen.o ft_putendl_fd.o \
ft_strlcpy.o ft_strjoin.o ft_strmapi.o ft_strncmp.o \
ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_strlcat.o \
ft_tolower.o ft_toupper.o ft_memmove.o ft_substr.o \
ft_calloc.o ft_isalnum.o ft_uitoa.o ft_salloc.o

OBJS2 = ptf_flags.o ptf_flags2.o ft_printf.o \
ptf_1types.o ptf_2types.o ptf_3types.o

SRC = $(addprefix libft/, $(SRC_TMP))

HEADERS = "/libft/libft.h"

RULES = all clean fclean re bonus

FLAGS = -Wall -Wextra -Werror

.PHONY: $(RULES)

all : $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) $(PRINTF) -I $(HEADERS)
	ar rcs $(NAME) $(OBJS) $(OBJS2)

clean:
	rm -f $(OBJS) $(OBJS2)

fclean: clean
	rm -f $(NAME)

re: fclean all
