
FILES = main Harl

OBJ_DIR = obj/
SRCS =  $(addsuffix .cpp, $(FILES))
OBJS =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CC = c++
CFLAGS = -Wall -Wextra  -std=c++98 -IInclude

NAME = HarlFilter

all : $(TEST_FILE) $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC)  $(CFLAGS) -o $(NAME) $(OBJS)

obj/%.o: %.cpp
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