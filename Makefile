# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-boud <ale-boud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 23:28:51 by ale-boud          #+#    #+#              #
#    Updated: 2023/04/26 14:15:23 by ale-boud         ###   ########.fr        #
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

CFLAGS := -g -c $(CWARN) -Ilibft

# ---
# Lib information
# ---

NAME := libftprintf.a
LIBFT := libft.a

SRCS := ft_printf.c ft_printf_arg.c ft_printf_conv.c ft_print_pad.c ft_printf_itoa.c
OBJS := $(SRCS:%.c=%.o)
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
	$(MAKE) -C libft
	mv libft/libft.a .

$(NAME): $(OBJS) $(LIBFT)
	mv $(LIBFT) $@
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -o $@ $<
