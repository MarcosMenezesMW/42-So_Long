NAME		=	so_long

MLX_DIR		=	./minilibx/

SRC_DIR		=	./src/

BNS_DIR		=	./src_bonus/

HEADER		= 	./src/so_long.h

BNS_HEADER	=	./src_bonus/so_long_bonus.h

SRC_FILES	=	error_handling.c \
				game_utils.c \
				image_printing.c \
				player_movement.c \
				print_sprites.c \
				sprites_utils.c \
				utils.c \
				so_long.c
				
SRC_BONUS 	=	so_long_bonus.c \
				animation_bonus.c \
				enemy_bonus.c \
				error_handling_bonus.c \
				game_utils_bonus.c \
				image_printing_bonus.c \
				player_movement_bonus.c \
				print_sprites_bonus.c \
				sprites_utils_bonus.c \
				utils_bonus.c 

INCLUDES	=	./minilibx/mlx.h
CC			=	clang
FLAGS		=	-g -Wall -Wextra -Werror -I $(INCLUDES)
LIBS		= 	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm

SRCIMAGES	=	./imgs/

BSRCS		=	$(addprefix $(BNS_DIR),$(SRC_BONUS))
SRCS 		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(SRCS:c=o)
BONUSOBJS	=	$(BSRCS:c=o)

all: $(NAME)

$(NAME):	$(OBJS) 
				cd $(MLX_DIR) && ./configure
				$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS)

bonus:		$(BONUSOBJS)
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