NAME	= webserve

SRC		= main.cpp Socket.cpp server.cpp
				
all: $(NAME)

$(NAME):
	c++ -Wall -Werror -Wextra -std=c++98 $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all