# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szhakypo <szhakypo@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 17:16:06 by szhakypo          #+#    #+#              #
#    Updated: 2022/02/13 16:25:21 by szhakypo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_isprint.c\
		ft_isascii.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_calloc.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_isdigit.c\
		ft_strlcat.c\
		ft_itoa.c\
		ft_strdup.c\
		ft_strtrim.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putnbr_fd.c\
		ft_split.c\

BONUS_SRCS  = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
    ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
    ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(patsubst %.c, %.o,$(LIST))
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs


all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $?

$(NAME) : $(BONUS_OBJS)
	$(AR) $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re :	fclean all
	
.PHONY : bonus all clean fclean re
