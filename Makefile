NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = -I./include
SRC_DIR = ./src
SRCS_DIR_PRINTF = ./src/printf
FILES = client minitalk_utils
FILES_PRINTF = ft_itoa ft_printf printf_utils

OBJS = $(addprefix $(SRC_DIR)/, $(addsuffix .o, $(FILES_C)))
OBJS_PRINTF = $(addprefix $(SRCS_DIR_PRINTF)/, $(addsuffix .o, $(FILES_PRINTF)))

all: $(NAME)

%.o: %.c
	$(CC) $(INC) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_PRINTF)
	$(CC) $(OBJS) $(OBJS_PRINTF) $(CFLAGS) $(INC) -o $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re