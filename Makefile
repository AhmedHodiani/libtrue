CC = cc
CFLAGS = -Wall -Wextra -Wall -I$(INC_DIR)

SRC_DIR = src
INC_DIR = include

BUILD_PATH ?= ./build
LIB_NAME = $(BUILD_PATH)/libtrue.a


# ================================ true_linked_list ================================ #
TRUE_LINKED_LIST_SRCS = src/true_linked_list/init.c \
						src/true_linked_list/insert.c \
						src/true_linked_list/clear.c \
						src/true_linked_list/pop.c \
						src/true_linked_list/loggers.c \
						src/true_linked_list/shift.c \
						src/true_linked_list/dup.c

TRUE_LINKED_LIST_OBJS		=	$(TRUE_LINKED_LIST_SRCS:src/true_linked_list/%.c=$(BUILD_PATH)/obj/%.o)
# ================================================================================== #


OBJS = $(TRUE_LINKED_LIST_OBJS)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJS)
	ar rcs $@ $^

$(BUILD_PATH)/obj/%.o: src/true_linked_list/%.c
	@mkdir -p $(BUILD_PATH)/obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(BUILD_PATH)/obj

fclean: clean
	@rm -rf $(BUILD_PATH)

re: fclean all

.PHONY: all clean fclean re
