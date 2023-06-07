# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 15:46:57 by gloms             #+#    #+#              #
#    Updated: 2023/06/03 01:05:23 by gloms            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------------------------ Sources -----------------------------

NAME = so_long

SRCS =	so_long.c \
		map_parser_1.c \
		map_parser_2.c \
		get_next_line.c \
		get_next_line_utils.c \
		texture_setup.c \
		animations.c \
		collusions.c \
		collusions2.c \
		valid_way.c \
		putnbr.c

OBJS = $(SRCS:.c=.o)

# ------------------------------ Flags -------------------------------

GCC = @gcc  -Wall -Werror -Wextra

# ------------------------------ Colors ------------------------------

# Colors

GREY 	 := "\033[1;30m"
RED 	 :=	"\033[1;31m"
GREEN 	 := "\033[1;32m"
YELLOW 	 := "\033[1;33m"
BLUE	 :=	"\033[1;36m"
PURPLE	 :=	"\033[1;35m"
WHITE	 :=	"\033[1;37m"
END		 :=	"\033[0;0m"

# ------------------------------ Messages ------------------------------

MAKE_MESS		= • Make :

FILES_OK		= has been successfully compiled!

FILES_DELETE	= • Clean : please make am fclean to delete so_long.exe

FCLEAN_DELETE	= • Fclean : so_long.exe was been successfully deleted!

# ------------------------------ so_long --------------------------------

all: $(NAME)

$(NAME):
	@$(GCC) $(SRCS) -o $(NAME) MLX42/build/libmlx42.a -I include -lglfw -L "/Users/rbrendle/.brew/opt/glfw/lib/"
	@echo ${GREEN}"$(MAKE_MESS) $(NAME) $(FILES_OK)"${END}

# --  ---------------------------- Rules -----------------------------------

clean:
	@rm -rf ${OBJS}
	@echo ${RED}"$(FILES_DELETE)"${END}

fclean: clean 
	@rm -rf $(NAME)
	@echo ${RED}"$(FCLEAN_DELETE)"${END}

re : fclean all