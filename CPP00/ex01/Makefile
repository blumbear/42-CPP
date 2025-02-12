
FILES = main Contact PhoneBook print

SRC_DIR = src/
OBJ_DIR = obj/
SRCS =  $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))
OBJS =  $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -IInclude

NAME = PhoneBook

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make

.PHONY : all clean fclean re