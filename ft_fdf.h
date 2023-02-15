/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/12 15:27:26 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "mlx.h"
# include<unistd.h>
# include<math.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include "libft/libft.h"

# define __NTR -100 //Nothing To Report
# define __ON_DESTROY 17 //Button x window killer
# define __ON_KEYDOWN 2
# define __KEYPRESSMASK 1L<<0
# define __ESC 65307

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