NAME		=	so_long.a

MLX_DIR		=	./minilibx/

SRC_FILES	=	error_handling.c game_utils.c player_movement.c \
				print_sprites.c so_long.c sprites_utils.c utils.c

CC			=	clang
FLAGS		=	-g -Wall -Wextra -Werror -I includes.
LIBS		= 	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCIMAGES	=	./imgs/

SRCS 		=	$(SRC_FILES)
OBJS		=	$(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
				cd $(MLX_DIR) && ./configure
				$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re