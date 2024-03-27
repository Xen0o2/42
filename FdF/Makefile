# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 13:44:41 by alecoutr          #+#    #+#              #
#    Updated: 2023/03/16 15:15:06 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	main.c \
 		${wildcard functions/*/*.c}
				
GCC = gcc -Wall -Wextra -Werror

$(NAME):
	$(GCC) $(SRCS) -o $(NAME) libmlx42.a -I include -lglfw -L "/Users/alecoutr/.brew/opt/glfw/lib/"

all: $(NAME)

clean:
	rm $(NAME)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

## $(GCC) $(SRCS) -o $(NAME) libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"