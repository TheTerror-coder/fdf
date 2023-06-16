# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 15:29:01 by TheTerror         #+#    #+#              #
#    Updated: 2023/06/16 15:11:20 by TheTerror        ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = ../fdf

FDF_PATH =			../
LIBFT_PATH = 		../libft/
DRAW_TOOLS_PATH = 	../draw_tools/
UTILS_PATH = 		../utils/
DATA_TOOLS_PATH = 	../data_tools/
EVENTS_TOOLS_PATH =	../events_tools/

INCLUDE_FT_LOCALS = $(DRAW_TOOLS_PATH)ft_local.h $(DATA_TOOLS_PATH)ft_local.h 
INCLUDE_BONUS = 	$(FDF_PATH)ft_fdf.h $(FDF_PATH)ft_preprocss.h $(INCLUDE_FT_LOCALS) $(DRAW_TOOLS_PATH)ft_draw_tools.h $(UTILS_PATH)ft_utils.h \
					$(DATA_TOOLS_PATH)ft_data_tools.h $(LIBFT_PATH)libft.h $(EVENTS_TOOLS_PATH)ft_events_tools.h \
					ft_bonus.h

CC = 				cc
CFLAGS=				-Wall -Werror -Wextra
MLX_OBJ_OPTIONS =	-I/usr/include -Imlx_linux -O3
MLX_LINK_OPTIONS =	-L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
RM =				rm -rf

LIBFT_LIB = libft.a
SRC_EVENTS_TOOLS = $(addprefix $(EVENTS_TOOLS_PATH), ft_zoom.c ft_translate.c ft_render.c ft_rotate.c ft_changeview.c ft_altitude.c)
SRC_DRAW_TOOLS = $(addprefix $(DRAW_TOOLS_PATH), ft_drawer.c ft_temp_utils.c ft_spot.c ft_trace.c ft_drw_utils.c)
SRC_UTILS = $(addprefix $(UTILS_PATH), ft_utils1.c ft_utils2.c ft_initmem.c ft_freemem.c ft_mlx_utils.c ft_keepnum.c)
SRC_DATA_TOOLS = $(addprefix $(DATA_TOOLS_PATH), ft_getdata.c ft_datatools_utils.c ft_setvectors.c)
SRC_BONUS = ft_bonus.c $(FDF_PATH)ft_fdf.c $(SRC_DATA_TOOLS) $(SRC_DRAW_TOOLS) $(SRC_UTILS) $(SRC_EVENTS_TOOLS)


OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : make_libft $(NAME)

%.o : %.c $(INCLUDE_BONUS) $(LIBFT_PATH)$(LIBFT_LIB)
	$(CC) $(CFLAGS) $(MLX_OBJ_OPTIONS) -c $< -o $@

make_libft :
	make -C $(LIBFT_PATH)

$(NAME): $(OBJ_BONUS) $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) $^ $(LIBFT_PATH)$(LIBFT_LIB) $(MLX_LINK_OPTIONS) -o $@

clean :
	@make clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ_BONUS)
fclean : clean
	@make fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
re : fclean all