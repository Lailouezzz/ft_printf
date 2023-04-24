# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/04/24 17:44:00 by ale-boud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---
# Tools
# ---

MKDIR := mkdir
RM := rm -f

# ---
# Build variables
# ---

# Compiler

CC := gcc

CWARN := all extra error
CWARN := $(CWARN:%=-W%)

CFLAGS := -c $(CWARN) -Ilibft

# ---
# Lib information
# ---

NAME := libftprintf.a
LIBFT := libft/libft.a

SRCS := ft_printf.c ft_printf_arg.c ft_printf_conv.c
OBJS := $(SRCS:%.c=%.o) $(LIBFT)
SRCS_BONUS := 
OBJS_BONUS := $(SRCS_BONUS:%.c=%.o)

# ---
#  General targets
# ---

# Build everything

all: $(NAME)

# Mostly clean (clean everything without the end result)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

# Clean everything

fclean: clean
	$(RM) $(NAME)

# Rebuild

re: fclean all

# Bonus

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^
	
.PHONY: all clean fclean re bonus

# ---
# Build targets
# ---

$(LIBFT):
	(cd libft && make all)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ $<
