# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 12:04:55 by alecoutr          #+#    #+#              #
#    Updated: 2023/06/13 12:54:36 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brain
SRCS		= srcs/main.cpp
INCLUDES	= -I ./includes

OBJS		= $(SRCS:.cpp=.o)
FLAGS		= -Wall -Wextra -Werror -g -g3 -std=c++98
CPP			= c++ $(FLAGS)

$(NAME)	: $(OBJS)
	$(CPP) $(OBJS) -o $(NAME) $(INCLUDES)

all	: $(NAME)

.cpp.o :
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o) $(INCLUDES)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all
