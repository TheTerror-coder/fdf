/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:36:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 14:03:23 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_local.h"

void	ft_join_pt(t_img *img, double x0, double m, t_coord *pt);
void	ft_vert_line(t_img *img, double y0, t_coord *pt);
void	ft_hor_line(t_img *img, double x0, t_coord *pt);

void	ft_trace(t_img *img, t_coord *pt1, t_coord *pt2)
{
	double	dx;
	double	dy;

	dx = pt2->x - pt1->x;
	dy = (pt2->y - pt1->y);
	if (dx == 0)
	{
		if (dy < 0)
			ft_vert_line(img, pt2->y, pt1);
		if (dy > 0)
			ft_vert_line(img, pt1->y, pt2);
	}
	else if (dy == 0)
	{
		if (dx < 0)
			ft_hor_line(img, pt2->x, pt1);
		if (dx > 0)
			ft_hor_line(img, pt1->x, pt2);
	}
	else if (dx < 0)
		ft_join_pt(img, pt2->x, (dy / dx), pt1);
	else if (dx > 0)
		ft_join_pt(img, pt1->x, (dy / dx), pt2);
}

void	ft_join_pt(t_img *img, double x0, double m, t_coord *pt)
{
	double	y;

	y = 0;
	while (x0 <= pt->x)
	{
		y = m * x0 + (pt->y - m * pt->x);
		if (ft_checkinframe(x0, y, _HEIGHT, _WIDHT) != __FALSE)
			my_mlx_pixel_put(img, x0, y, img->color);
		x0++;
	}
}

void	ft_vert_line(t_img *img, double y0, t_coord *pt)
{
	double	x;

	x = pt->x;
	while (y0 <= pt->y)
	{
		if (ft_checkinframe(x, y0, _HEIGHT, _WIDHT) != __FALSE)
			my_mlx_pixel_put(img, x, y0, img->color);
		y0++;
	}
}

void	ft_hor_line(t_img *img, double x0, t_coord *pt)
{
	double	y;

	y = pt->y;
	while (x0 <= pt->x)
	{
		if (ft_checkinframe(x0, y, _HEIGHT, _WIDHT) != __FALSE)
			my_mlx_pixel_put(img, x0, y, img->color);
		x0++;
	}
}
