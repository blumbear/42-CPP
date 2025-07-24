
FILES = main RPN

OBJ_DIR = obj/
SRCS =  $(addsuffix .cpp, $(FILES))
OBJS =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

NAME = RPN

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

test :
	make
	./test.sh

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME) .gdb_history

re : fclean
	make

.PHONY : all clean fclean re