
FILES = main AMateria Character Cure Ice

OBJ_DIR = obj/
SRC_DIR = src/
SRCS =  $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJS =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -IInclude

NAME = Interface&Recap

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re