/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:51:36 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:09:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCSS_H
# define FT_PREPROCSS_H

# define _SIZE_X 1840 //window's x size
# define _SIZE_Y 900 //window's y size
# define _WIDHT 1840 //image's widht
# define _HEIGHT 900 //image's height

# define __NTR -100 //Nothing To Report
# define __ON_DESTROY 17 //Button x window killer
# define __ON_KEYDOWN 2
# define __KEYPRESSMASK 1L<<0
# define __ESC 65307 //ESCape key
# define __STEP 30 //step lenght between two points

# define _OX 500
# define _OY 100

# define PERC_J 0.5 //Percentage of STEP defining the step on j axis
# define PERC_K 8.0 //Percentage of STEP defining the step on k axis

typedef struct	s_coord
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct	s_vec
{
	t_coord	*o;
	t_coord *e;
}				t_vec;

typedef struct s_img
{
	char	*addr;
	int		bpp;	//bits per pixel
	int		size_line;
	int		endian;
	int		color;
	void	*image;
}				t_img;


typedef enum e_bool
{
	__FALSE = -999999,
	__TRUE = -111111
}				t_bool;

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
}				t_vars;

#endif