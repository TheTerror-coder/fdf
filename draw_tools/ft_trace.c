/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 16:48:05 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_tools.h"

void	ft_join_pt(t_img *img, double x0, double m, t_coord *pt, int color);
void	ft_vert_line(t_img *img, double y0, t_coord *pt, int color);
void	ft_hor_line(t_img *img, double x0, t_coord *pt, int color);

void	ft_trace(t_img *img, t_coord *pt1, t_coord *pt2, int color)
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

void	ft_join_pt(t_img *img, double x0, double m, t_coord *pt, int color)
{
	double	y;

	y = 0;
	while (x0 <= pt->x)
	{
		y = m * x0 + (pt->y - m * pt->x);
		if (ft_checkinframe(x0, y, _HEIGHT, _WIDHT) != __FALSE)
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
