NAME = fdf
LIBFT_PATH = 		include/libft/
GNL_PATH = 			include/get_next_line/
DRAW_TOOLS_PATH = 	draw_tools/
UTILS_PATH = 		utils/
DATA_TOOLS_PATH = 	data_tools/

INCLUDE = 	ft_fdf.h ft_preprocss.h $(DRAW_TOOLS_PATH)ft_draw_tools.h $(UTILS_PATH)ft_utils.h \
			$(DATA_TOOLS_PATH)ft_getdata.h $(LIBFT_PATH)libft.h $(GNL_PATH)get_next_line.h

CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
MLX_OBJ_OPTIONS =	-I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM =				rm -rf

LIBFT_LIB = libft.a
SRC_DRAW_TOOLS = $(addprefix $(DRAW_TOOLS_PATH), ft_drawer.c ft_spot.c ft_trace.c ft_drw_utils.c)
SRC_UTILS = $(addprefix $(UTILS_PATH), ft_utils1.c ft_utils2.c ft_init_del.c ft_mlx_utils.c ft_keepnum.c)
SRC_DATA_TOOLS = $(addprefix $(DATA_TOOLS_PATH), ft_getdata.c ft_indextab.c ft_setvectors.c)
SRC_GNL = $(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)
SRC = $(SRC_DATA_TOOLS) $(SRC_GNL) ft_fdf.c $(SRC_DRAW_TOOLS) $(SRC_UTILS)
OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)$(LIBFT_LIB) .
	$(CC) $^ $(LIBFT_LIB) $(MLX_LINK_OPTIONS) -o $@

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
fclean : clean
	make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
re : fclean all