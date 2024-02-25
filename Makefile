# Necessisities
CC := cc
CFLAGS := -Wall -Wextra -Werror -Wpedantic -g3

NAME := sort

INCLUDE := sort.h
INCLUDES := $(addprefix includes/, $(INCLUDE))

SRC  := main.c bubble_sort.c quick_sort.c merge_sort.c
SRCS := $(addprefix srcs/, $(SRC));

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ -Iincludes $(SRCS)

sanitize :
	$(CC) $(CFLAGS) -fsanitize=address,undefined -o $@ -Iincludes $(SRCS)

clean :
	@rm -rf $(NAME)
	@rm -rf sanitize

fclean : clean

re : fclean all
