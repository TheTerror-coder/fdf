/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:05:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 02:05:58 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render_op(t_vars *xvar, t_img *img);

t_bool	ft_render(t_vars *xvar)
{
	t_img	*img;

	xvar->fdbk = __TRUE;
	if (!xvar->flgzoom)
	{
		xvar->zmstep += __ZOOMSTEP;
		xvar->flgzoom = 1;
	}
	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (__FALSE);
	img->image = mlx_new_image(xvar->mlx, _WIDHT, _HEIGHT);
	if (img->image)
	{
		img->addr = mlx_get_data_addr(img->image, &(img->bpp), \
						&(img->size_line), &(img->endian));
		xvar->fdbk = ft_render_op(xvar, img);
		return (xvar->fdbk);
	}
	free(img);
	return (xvar->fdbk);
}

t_bool	ft_render_op(t_vars *xvar, t_img *img)
{
	if (xvar->img->image)
		mlx_destroy_image(xvar->mlx, xvar->img->image);
	free(xvar->img);
	xvar->img = img;
	xvar->fdbk = ft_fdf_op(xvar);
	if (xvar->fdbk == __TRUE)
		mlx_put_image_to_window(xvar->mlx, xvar->win, xvar->img->image, 0, 0);
	return (xvar->fdbk);
}
