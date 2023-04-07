/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:48:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 18:30:50 by TheTerror        ###   ########lyon.fr   */
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
	*(unsigned int*)dst = color;
}

int	ft_xbutton_close(t_vars *xvar)
{
	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (0);
}

int	ft_keyhook(int keycode, t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	if (keycode == __LEFT)
		xvar->fdbk = ft_translateleft(xvar);
	else if (keycode == __RIGHT)
		xvar->fdbk = ft_translateright(xvar);
	else if (keycode == __UP)
		xvar->fdbk = ft_translateup(xvar);
	else if (keycode == __DOWN)
		xvar->fdbk = ft_translatedown(xvar);
	else if (keycode == __LMIN)
		xvar->fdbk = ft_lower(xvar);
	else if (keycode == __HMIN)
		xvar->fdbk = ft_higher(xvar);
	else if (keycode == __ESC)
		ft_exitprocss(EXIT_SUCCESS, xvar);
	if (xvar->fdbk == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	return (0);
}

int	ft_mousehook(int button, int x, int y, t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	if (button == __ZOOMIN)
		xvar->fdbk = ft_zoomin(xvar);
	else if (button == __ZOOMOUT)
		xvar->fdbk = ft_zoomout(xvar);
	else if (button == __RIGHTBUTTON)
		xvar->fdbk = ft_rotateright(xvar);
	else if (button == __LEFTBUTTON)
		xvar->fdbk = ft_rotateleft(xvar);
	else if (button == __WHEELBUTTON)
		xvar->fdbk = ft_flat(xvar);
	if (xvar->fdbk == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	(void) x;
	(void) y;
	return (0);
}
