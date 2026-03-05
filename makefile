# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ezukaz <katakaha@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 20:49:15 by Ezukaz            #+#    #+#              #
#    Updated: 2026/03/05 20:49:15 by Ezukaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap # This is not a library so no .a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -MMD # -g for debugging. Makes the .o file heavier so remove it if you want to save space but it's good to leave it for future debugging
# -MMD makes dependency files. Without .d there is no way for the compiler to tell if a file depends on a header, so it can't check if they need to recompile if a header was changed. If a source file was changed then it can check by checking the timestamp, but whether or not a file depends on a header is up to that file so it doesn't check header timestamps. The .d lets it know that it should check the header timestamp because it is needed
RM			= rm -rf # -rf r for recursive and f for force. So remove folder and its contents
IFLAGS		= -I $(INCDIR)

SRCDIR		= src
OBJDIR		= obj
INCDIR		= inc

# Libraries
LIBFTDIR	= lib/libft
LIBFT		= $(LIBFTDIR)/libft.a
#PRINTFDIR	= lib/printf
#PRINTF		= $(PRINTFDIR)/printf.a

# Project files
SRC		= $(addsuffix .c, \
			validate_parse \
			operations \
			cost_calc \
			do_min \
			sort \
			utils \
			main)

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP		= $(OBJ:.o=.d)

all: $(NAME)

# Linking
$(NAME): $(OBJ) $(LIBFT) # Add $(PRINTF) after $(LIBFT) if you want to use printf
# This is called linking, and for this assignment we are making an executable, so no AR. AR is for making a library which only needs headers files to compile and make a .o file. In this case we are linking so the actual files are also needed. If something depends on another thing, the thing depending comes first. So if i were to add printf to the mix then $(PRINTF) would come before $(LIBFT)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LIBFT) -o $@

# Compiling
$(OBJDIR)/%.o: $(SRCDIR)/%.c
# -p shell command. Make that directory if not existing with all of its parent directories as well
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
# When you run `cc` (or `gcc`) on `.c` files without `-c`, the compiler does both compilation and linking in one step:
#
# - Each `.c` file is first compiled to an object file in memory
# - Then the object files are linked together to produce the final executable
# - You can use `-o <name>` to specify the output name
#
# If you add `-c`, the compiler only compiles the `.c` file to a `.o` object file and does not link.

# Making Libft
$(LIBFT):
# -C means go into that directory and do command
# $(MAKE) is the make command with any flags you might have added when you called on it. It is considered good practice to use this instead of normal make
	$(MAKE) -C $(LIBFTDIR)

# If you want to add printf
#$(PRINTF):
#	$(MAKE) -C $(PRINTFDIR)

-include $(DEP) # -include means to include dependency files if they exist and don't freak out even if they don't

clean:
# Since the dependency files also live in $(OBJDIR) they will be removed as well. Just what we want
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
