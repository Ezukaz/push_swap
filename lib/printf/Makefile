# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 12:11:15 by katakaha          #+#    #+#              #
#    Updated: 2026/03/05 19:02:12 by Ezukaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
AR		= ar
ARFLAGS	= rcs

SRCDIR	= srcs
INCDIR	= incs
OBJDIR	= objs

SRCS	= $(addprefix ft_, $(addsuffix .c, \
	printf \
	printf_utils \
	specifier_funcs_hex \
	specifier_funcs_puts))

OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

IFLAGS	= -I $(INCDIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -MMD -c $< -o $@

DEPS		= $(OBJS:.o=.d)
-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
