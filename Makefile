# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hclaude <hclaude@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 14:52:17 by hclaude           #+#    #+#              #
#    Updated: 2024/09/30 17:37:46 by hclaude          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = @gcc

AR = ar

ARFLAGS = rcs

CFLAGS = -Wall -Werror -Wextra -g3

OBJFILES = $(SRCFILES:.c=.o)
OBJFILESBONUS = $(OBJFILES) $(SRCBONUS:.c=.o)
OBJFILESGNL = $(OBJFILESBONUS) $(SRCgnl:.c=.o)
OBJFILESPRINTF = $(SRCprintf:.c=.o)

SRCFILES = src/libft/ft_atoi.c  \
src/libft/ft_atol.c \
src/libft/ft_bzero.c \
src/libft/ft_calloc.c \
src/libft/ft_isalnum.c \
src/libft/ft_isalpha.c \
src/libft/ft_isascii.c \
src/libft/ft_isdigit.c \
src/libft/ft_isprint.c \
src/libft/ft_memchr.c \
src/libft/ft_strndup.c \
src/libft/ft_memcmp.c \
src/libft/ft_memcpy.c \
src/libft/ft_memmove.c \
src/libft/ft_memset.c \
src/libft/ft_strchr.c \
src/libft/ft_strdup.c \
src/libft/ft_strjoin.c \
src/libft/ft_strlcat.c \
src/libft/ft_strlcpy.c \
src/libft/ft_strlen.c \
src/libft/ft_strncmp.c \
src/libft/ft_strcat.c \
src/libft/ft_strnstr.c \
src/libft/ft_strrchr.c \
src/libft/ft_strtrim.c \
src/libft/ft_substr.c \
src/libft/ft_tolower.c \
src/libft/ft_toupper.c \
src/libft/ft_putchar_fd.c \
src/libft/ft_putstr_fd.c \
src/libft/ft_putendl_fd.c \
src/libft/ft_putnbr_fd.c \
src/libft/ft_split.c \
src/libft/ft_itoa.c \
src/libft/ft_strmapi.c \
src/libft/ft_striteri.c \
src/garbage_collector/call_functions.c \
src/garbage_collector/garbage_collector.c

SRCBONUS = src/libft/ft_lstnew_bonus.c \
src/libft/ft_lstadd_front_bonus.c \
src/libft/ft_lstsize_bonus.c \
src/libft/ft_lstlast_bonus.c \
src/libft/ft_lstadd_back_bonus.c \
src/libft/ft_lstdelone_bonus.c \
src/libft/ft_lstclear_bonus.c \
src/libft/ft_lstiter_bonus.c \
src/libft/ft_lstmap_bonus.c

SRCgnl = src/get_next_line/get_next_line.c \

SRCprintf = src/printf/ft_printf.c src/printf/ft_put_unsigned.c src/printf/ft_put.c \
src/printf/ft_puthexa.c src/printf/ft_putpointer.c

all : $(NAME)

$(NAME) : $(OBJFILES) $(OBJFILESBONUS) $(OBJFILESGNL) $(OBJFILESPRINTF)
	@$(AR) $(ARFLAGS) $@ $^
	@$(eval CURRENT_FILES=$(shell echo $$(($(CURRENT_FILES)+1))))
	@echo "\033[32mturbo_libft compiled\033[0m"

clean :
	@rm -rf $(OBJFILES) $(OBJFILESBONUS) $(OBJFILESGNL) $(OBJFILESPRINTF)
	@echo "\033[31mclean turbo_libft\033[0m"

fclean : clean
	@rm -rf $(NAME)

re : fclean all

big : all clean

.PHONY: all clean fclean re big
