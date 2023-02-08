NAME = prog
LIBFT_PATH = libft/

INCLUDE = ft_fdf.h $(LIBFT_PATH)

CC = cc
CFLAGS= -Wall -Werror -Wextra
MLX_OBJ_OPTIONS = -I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -rf


SRC = ft_fdf.c
OBJ = $(SRC:.c=.o)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $< $(MLX_LINK_OPTIONS) -o $@

clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all