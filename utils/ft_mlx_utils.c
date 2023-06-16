/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:48:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/16 16:47:23 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_bool	ft_set_mlx(t_vars *xvar)
{
	xvar->mlx = mlx_init();
	if (!xvar->mlx)
		return (__FALSE);
	xvar->win = mlx_new_window(xvar->mlx, _SIZE_X, _SIZE_Y, "fdf");
	if (!xvar->win)
		return (__FALSE);
	xvar->img->image = mlx_new_image(xvar->mlx, _WIDHT, _HEIGHT);
	if (!xvar->img->image)
		return (__FALSE);
	xvar->img->addr = mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	return (__TRUE);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_xbutton_close(t_vars *xvar)
{
	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (0);
}
