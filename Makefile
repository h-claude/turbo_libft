# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:52:17 by hclaude           #+#    #+#              #
#    Updated: 2024/02/03 19:07:47 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

AR = ar

ARFLAGS = rcs

CFLAGS = -Wall -Werror -Wextra

OBJFILES = $(SRCFILES:.c=.o)
OBJFILESBONUS = $(OBJFILES) $(SRCBONUS:.c=.o)
OBJFILESGNL = $(OBJFILESBONUS) $(SRCgnl:.c=.o)

SRCFILES = ft_atoi.c  \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memchr.c \
ft_strndup.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strcat.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c

SRCBONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

SRCgnl = get_next_line/get_next_line_bonus.c \

all : $(NAME)

$(NAME) : $(OBJFILES) $(OBJFILESBONUS) $(OBJFILESGNL)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES) $(OBJFILESBONUS) $(OBJFILESGNL)

clean :
	@rm -rf $(OBJFILES) $(OBJFILESBONUS) $(OBJFILESGNL)

fclean : clean
	@rm -rf *.a

re : fclean all
