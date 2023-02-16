/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocss.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:51:36 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/16 01:35:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PREPROCSS_H
# define FT_PREPROCSS_H

# define __NTR -100 //Nothing To Report
# define __ON_DESTROY 17 //Button x window killer
# define __ON_KEYDOWN 2
# define __KEYPRESSMASK 1L<<0
# define __ESC 65307

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;

typedef struct s_img
{
	char	*addr;
	int		bpp;	//bits per pixel
	int		size_line;
	int		endian;
	void	*image;
	int		x_img;
	int		y_img;
}				t_img;

typedef struct s_vars
{
	int		fd;
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_vars;

typedef enum e_bool
{
	__FALSE = 0,
	__TRUE = 1
}				t_bool;

#endif