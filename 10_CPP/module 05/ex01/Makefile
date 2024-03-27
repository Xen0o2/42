# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <alecoutr@student.42mulhouse.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 18:40:53 by alecoutr          #+#    #+#              #
#    Updated: 2023/06/30 16:50:46 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Form
SRCS		= srcs/main.cpp \
			  srcs/Bureaucrat.cpp \
			  srcs/Form.cpp

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
