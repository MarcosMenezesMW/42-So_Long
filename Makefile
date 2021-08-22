NAME		=	so_long.a

MLX_DIR		=	./minilibx-linux/test/
MLX			=	$(MLX_DIR)/lib_linux.a

SRC_FILES	=	so_long.c sprites_utils.c game_utils.c

CC			=	clang
FLAGS		=	-Wall -Wextra -Werror -I$(SRCPATH) -Imlx_linux -03 -c

SRCIMAGES	=	./imgs/
SRCMAPS 	=	./maps/

SRCS 		=	$(SRC_FILES)
OBJS		=	$(SRCS:c=o)

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(RM) $(NAME)
		$(AR) rcs $(NAME) $(OBJS)

$(MLX):
		make -C $(MLX_DIR)

%.o: %.c
	@clang $(FLAGS) -I /printf -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	make -C ${MLX_DIR} fclean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY = all clean fclean re