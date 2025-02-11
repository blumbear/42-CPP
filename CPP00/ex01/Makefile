
SRCS = PhoneBook Contact main

INCLUDE = PhoneBook Contact 

SRC = $(addsuffix .cpp, $(SRCS))
OBJ = $(addsuffix .o, $(SRCS))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o : %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re