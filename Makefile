# Necessisities
CC := cc
CFLAGS := -Wall -Wextra -Werror -Wpedantic -fsanitize=address,undefined -g3

NAME := sort

INCLUDE := sort.h
INCLUDES := $(addprefix includes/, $(INCLUDE))

SRC  := main.c bubble_sort.c quick_sort.c
SRCS := $(addprefix srcs/, $(SRC));

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ -Iincludes $(SRCS)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
