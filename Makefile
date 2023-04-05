NAME = fdf
LIBFT_PATH = 		include/libft/
GNL_PATH = 			include/get_next_line/
DRAW_TOOLS_PATH = 	draw_tools/
UTILS_PATH = 		utils/
DATA_TOOLS_PATH = 	data_tools/

INCLUDE_FT_LOCALS = $(DRAW_TOOLS_PATH)ft_local.h $(DATA_TOOLS_PATH)ft_local.h 
INCLUDE = 	ft_fdf.h ft_preprocss.h $(INCLUDE_FT_LOCALS) $(DRAW_TOOLS_PATH)ft_draw_tools.h $(UTILS_PATH)ft_utils.h \
			$(DATA_TOOLS_PATH)ft_data_tools.h $(LIBFT_PATH)libft.h $(GNL_PATH)get_next_line.h

CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
MLX_OBJ_OPTIONS =	-I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS =	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM =				rm -rf

LIBFT_LIB = libft.a
SRC_DRAW_TOOLS = $(addprefix $(DRAW_TOOLS_PATH), ft_drawer.c ft_temp_utils.c ft_spot.c ft_trace.c ft_drw_utils.c)
SRC_UTILS = $(addprefix $(UTILS_PATH), ft_utils1.c ft_utils2.c ft_initmem.c ft_freemem.c ft_mlx_utils.c ft_keepnum.c)
SRC_DATA_TOOLS = $(addprefix $(DATA_TOOLS_PATH), ft_getdata.c ft_datatools_utils.c ft_setvectors.c)
SRC_GNL = $(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)
SRC = $(SRC_DATA_TOOLS) $(SRC_GNL) ft_fdf.c $(SRC_DRAW_TOOLS) $(SRC_UTILS)
OBJ = $(SRC:.c=.o)

all : make_libft $(NAME)

%.o : %.c $(INCLUDE) $(LIBFT_PATH)$(LIBFT_LIB)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@

make_libft :
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $^ $(LIBFT_PATH)$(LIBFT_LIB) $(MLX_LINK_OPTIONS) -o $@

clean :
	make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
fclean : clean
	make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
re : fclean all