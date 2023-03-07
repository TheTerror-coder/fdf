/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 00:39:33 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/05 14:58:06 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_join_pt(t_img *img, double x0, double m, t_coord *pt, int color)
{
	double	y;

	y = 0;
	while (x0 <= pt->x)
	{
		y = m * x0 + (pt->y - m * pt->x);
		if (ft_checkinframe(y, _HEIGHT, _WIDHT) != __FALSE && \
			ft_checkinframe(x0, _HEIGHT, _WIDHT) != __FALSE)
			my_mlx_pixel_put(img, x0, y, color);
		x0++;
	}
}

void	ft_vert_line(t_img *img, double y0, t_coord *pt, int color)
{
	double	x;

	x = pt->x;
	while (y0 <= pt->y)
	{
		my_mlx_pixel_put(img, x, y0, color);
		y0++;
	}
}

void	ft_hor_line(t_img *img, double x0, t_coord *pt, int color)
{
	double	y;

	y = pt->y;
	while (x0 <= pt->x)
	{
		my_mlx_pixel_put(img, x0, y, color);
		x0++;
	}
}

void	ft_drw_line(t_img *img, t_coord *pt1, t_coord *pt2, int color)
{
	double	dx;
	double	dy;

	dx = pt2->x - pt1->x;
	dy = (pt2->y - pt1->y);
	if (dx == 0)
	{
		if (dy < 0)
			ft_vert_line(img, pt2->y, pt1, color);
		if (dy > 0)
			ft_vert_line(img, pt1->y, pt2, color);
	}
	else if (dy == 0)
	{
		if (dx < 0)
			ft_hor_line(img, pt2->x, pt1, color);
		if (dx > 0)
			ft_hor_line(img, pt1->x, pt2, color);
	}
	else if (dx < 0)
		ft_join_pt(img, pt2->x, (dy / dx), pt1, color);
	else if (dx > 0)
		ft_join_pt(img, pt1->x, (dy / dx), pt2, color);
}

void	ft_drw_3dspot_op(t_vars *xvars, t_coord *o, t_coord *e, int color)
{
	t_coord	*pt1;
	t_coord	*pt2;

	pt1 = ft_calloc(1, sizeof(t_coord));
	pt2 = ft_calloc(1, sizeof(t_coord));
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	ft_add_step(pt1);
	ft_add_step(pt2);
	ft_ad_in3dspot(pt1);
	ft_ad_in3dspot(pt2);
	ft_drw_line(xvars->img, pt1, pt2, color);
	free(pt1);
	free(pt2);
}

void	ft_drw_3dspot(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;
	t_coord *j;
	t_coord *k;

	o = ft_calloc(1, sizeof(t_coord));
	i = ft_calloc(1, sizeof(t_coord));
	j = ft_calloc(1, sizeof(t_coord));
	k = ft_calloc(1, sizeof(t_coord));
	o->x = 0;
	o->y = 0;
	i->x = sin(1.047197551214944);
	i->y = cos(1.047197551214944);
	ft_drw_3dspot_op(xvar, o, i, 0xFF);
	j->x = - sin(1.047197551214944) - ft_percent(__STEP, PERC_J);
	j->y = cos(1.047197551214944) + ft_percent(__STEP, PERC_J);
	ft_drw_3dspot_op(xvar, o, j, 0xFF0000);
	k->x = 0;
	k->y = -1;
	ft_drw_3dspot_op(xvar, o, k, 0xFF00);
	free(o);
	free(i);
	free(j);
	free(k);
}

void	ft_drw_2dspot(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;

	o = ft_calloc(1, sizeof(t_coord));
	i = ft_calloc(1, sizeof(t_coord));
	o->x = - _OX;
	o->y = 0;
	i->x = - _OX + _WIDHT;
	i->y = 0;
	ft_ad_in3dspot(o);
	ft_ad_in3dspot(i);
	ft_drw_line(xvar->img, o, i, 0xFFFFFF);
	o->x = 0;
	o->y = - _OY;
	i->x = 0;
	i->y = - _OY + _HEIGHT;
	ft_ad_in3dspot(o);
	ft_ad_in3dspot(i);
	ft_drw_line(xvar->img, o, i, 0xFFFFFF);
	free(o);
	free(i);
}
