NAME		=	so_long

MLX_DIR		=	./minilibx/

SRC_FILES	=	error_handling.c game_utils.c player_movement.c \
				print_sprites.c so_long.c sprites_utils.c utils.c \
				image_printing.c
				
SRC_BONUS 	=	enemy.c animation.c

CC			=	clang
FLAGS		=	-g -Wall -Wextra -Werror -I includes.
LIBS		= 	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCIMAGES	=	./imgs/

BSRCS		=	$(SRC_BONUS)
SRCS 		=	$(SRC_FILES)
OBJS		=	$(SRCS:c=o)
BONUSOBJS	=	$(BSRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS) 
				cd $(MLX_DIR) && ./configure
				$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS)

bonus:
		$(BONUSOBJS)
		$(CC) $(FLAGS) -o $(NAME) $(BSRCS) $(LIBS)

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUSOBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re