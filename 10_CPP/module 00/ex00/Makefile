# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 10:17:25 by alecoutr          #+#    #+#              #
#    Updated: 2023/06/12 14:25:54 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
SRCS	= megaphone.cpp	
OBJS	= $(SRCS:.cpp=.o)
FLAGS	= -Wall -Wextra -Werror -g -g3 -std=c++98
CPP		= c++ $(FLAGS)

$(NAME)	: $(OBJS)
	$(CPP) $(OBJS) -o $(NAME)

all	: $(NAME)

.cpp.o :
	$(CPP) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all
