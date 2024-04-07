NAME=fractol
CC=cc
CFLAGS=-Wall -Wextra -Werror -I /usr/X11/include -g
LDFLAGS=-L /usr/X11/lib -lmlx -framework OpenGL -framework AppKit

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

SRCS=fractol.c \
     utils/utiles.c \
     utils/mandelbrot.c \
     utils/julia.c \
     utils/burningship.c \
     utils/ft_strncmp.c

OBJS=$(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	${CC} $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}$(GREEN)done${CLR_RMV}"

clean:
	@echo "$(RED)Removing ${CLR_RMV}objects files ${RED}..."
	rm -f $(OBJS)
	@echo "$(RED)Removing ${CLR_RMV}objects files ${RED}done${CLR_RMV}"

fclean: clean
	@echo "$(RED)Removing ${CLR_RMV}$(NAME) ${RED}..."
	rm -f $(NAME)
	@echo "$(RED)Removing ${CLR_RMV}$(NAME) ${RED}done${CLR_RMV}"

re: fclean all
