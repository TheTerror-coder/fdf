NAME = prog
LIBFT_PATH = libft/

INCLUDE = ft_fdf.h $(LIBFT_PATH)

CC = cc
CFLAGS= -Wall -Werror -Wextra
MLX_OBJ_OPTIONS = -I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -rf

LIBFT_LIB = libft.a
SRC = ft_fdf.c
OBJ = $(SRC:.c=.o)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)$(LIBFT_LIB) .
	$(CC) $< $(LIBFT_LIB) $(MLX_LINK_OPTIONS) -o $@

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
fclean : clean
	make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
re : fclean all