CC = cc
CFLAGS = -Wall -Wextra -Wall -I$(INC_DIR)

SRC_DIR = src
INC_DIR = include

LIB_NAME = libtrue.a


# ================================ true_linked_list ================================ #
TRUE_LINKED_LIST_SRCS = src/true_linked_list/init.c \
						src/true_linked_list/insert.c \
						src/true_linked_list/clear.c \
						src/true_linked_list/pop.c \
						src/true_linked_list/loggers.c \
						src/true_linked_list/shift.c \
						src/true_linked_list/dup.c

TRUE_LINKED_LIST_OBJS		=	$(TRUE_LINKED_LIST_SRCS:src/true_linked_list/%.c=obj/%.o)
# ================================================================================== #


OBJS = $(TRUE_LINKED_LIST_OBJS)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $@ $^

obj/%.o: src/true_linked_list/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
