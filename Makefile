# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hali-mah <hali-mah@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 12:49:48 by hali-mah            #+#    #+#              #
#    Updated: 2024/10/22 12:49:48 by hali-mah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libreay name
NAME = libftprintf.a

# Sources files
SRC = 
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# All rule
all: $(NAME)

# Build
$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

# Clean
clean:
		$(RM) $(OBJ)

# Fclean
fclean: clean
		$(RM) $(NAME)

# Rebuild
re:		fclean $(NAME)

.PHONY: all clean fclean re