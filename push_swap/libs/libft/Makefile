# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakaha <katakaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/25 19:21:57 by katakaha          #+#    #+#              #
#    Updated: 2025/10/29 19:18:28 by katakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
AR = ar
ARFLAGS = rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC = $(addprefix ft_, $(addsuffix .c, \
atoi \
bzero \
calloc \
isalnum \
isalpha \
isascii \
isdigit \
isprint \
memchr \
memcmp \
memcpy \
memmove \
memset \
strchr \
strdup \
strlcat \
strlcpy \
strlen \
strncmp \
strnstr \
strrchr \
tolower \
toupper \
substr \
strjoin \
strtrim \
split \
itoa \
strmapi \
striteri \
putchar_fd \
putstr_fd \
putendl_fd \
putnbr_fd))
BONUS_SRC = $(addprefix ft_lst, $(addsuffix _bonus.c, \
new \
add_front \
size \
last \
add_back \
delone \
clear \
iter \
map))

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus: fclean $(OBJ) $(BONUS_OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(BONUS_OBJ)

# ----------- OBJECTS -------------
%.o: %.c
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# ---------- DEPENDENCIES ----------
DEP = $(OBJ:.o=.d)
BONUS_DEP = $(BONUS_OBJ:.o=.d)

-include $(DEP) $(BONUS_DEP)

# ---------- CLEAN RULES -----------
clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(DEP) $(BONUS_DEP)

fclean: clean
	$(RM) $(NAME) $(wildcard test_*)

re: fclean all

# -------------- TEST ---------------
TEST ?=
TEST_SRC = ft_$(TEST).c
TEST_BIN = test_$(TEST)
TEST_MACRO = TEST

test: $(NAME)
	$(CC) $(CFLAGS) -g -fsanitize=address -lbsd -I. -D$(TEST_MACRO) \
		$(TEST_SRC) $(NAME) -o $(TEST_BIN)

run: test
	./$(TEST_BIN) | cat -e

.PHONY: all clean fclean re test bonus
