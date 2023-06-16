/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:51:36 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/16 17:59:30 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCSS_H
# define FT_PREPROCSS_H

# include "./libft/libft.h"

# define _SIZE_X_HONOR 1920		//screen's widht of the PC HONOR MAGICBOOK
# define _SIZE_Y_HONOR 1080		//screen's height of the PC HONOR MAGICBOOK
# define _SIZE_X_MAC 3840		//screen's widht of 42's MAC
# define _SIZE_Y_MAC 2160		//screen's height of 42's MAC

# define _SIZE_X _SIZE_X_MAC 		//window's x size
# define _SIZE_Y _SIZE_Y_MAC 		//window's y size
# define _WIDHT  _SIZE_X			//image's widht
# define _HEIGHT _SIZE_Y 			//image's height

# define __NTR -100 		//Nothing To Report
# define __ON_DESTROY 17 	//Button x window killer
# define __ON_KEYDOWN 2
# define __ON_MOUSEDOWN 4
# define __KEYPRESSMASK 1L
# define __BUTTONPRESSMASK 4L

/*KEYCODES*/
# define __ESC 65307 		//ESCape key
# define __H_ 104 		//h key
# define __L_ 108 		//l key
# define __ZOOMIN 4 		//mouse wheel
# define __ZOOMOUT 5 		//mouse wheel
# define __LEFT 65361 		//left key
# define __RIGHT 65363 		//right key
# define __UP 65362 		//up key
# define __DOWN 65364 		//down key
# define __LEFTBUTTON 1 	//mouse's left button
# define __RIGHTBUTTON 3 	//mouse's right button
# define __WHEELBUTTON 2 	//mouse's wheel button

# define __STEP 30			//step lenght between two points
# define __ZOOMSTEP 5 		//zoom's step lenght
# define __HEIGHTSTEP 2 	//zoom's step lenght

# define __ISOANGLE 1.047197551214944
/*
# define _OX ((_SIZE_X * 2) / 7)
# define _OY ((_SIZE_Y * 2) / 7)
*/
# define _OX 1000
# define _OY 600

# define PERC_J 0.5 		//Percentage of STEP defining the step on j axis
# define PERC_K 8.0 		//Percentage of STEP defining the step on k axis

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct s_vec
{
	t_coord	*o;
	t_coord	*e;
}				t_vec;

typedef struct s_img
{
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	void	*image;
}				t_img;

typedef struct s_vars
{
	int		fd;
	char	*map;
	void	*mlx;
	void	*win;
	t_img	*img;
	int		*indxtab;
	double	**z_data;
	t_vec	**list;
	int		ix_list;
	int		lenlist;
	int		jx;
	int		i;
	t_bool	fdbk;
	int		flgzoom;
	int		flg3d;
	double	zmstep;
	double	horstep;
	double	vertstep;
	double	angle;
	double	height;
}				t_vars;
#endif