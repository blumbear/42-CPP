
FILES = main

OBJ_DIR = obj/
SRCS =  $(addsuffix .cpp, $(FILES))
OBJS =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -IInclude

NAME = SedIsForLosers

TEST_FILE = test.txt

all : $(TEST_FILE) $(NAME)

$(TEST_FILE) :
	ls -lah >> test.txt

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME) $(TEST_FILE)  $(addsuffix .replace, $(TEST_FILE))

re : fclean
	make

.PHONY : all clean fclean re