/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:58:45 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:48:52 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_local.h"

void	ft_ad_in3dspot(t_coord *pt)
{
	pt->x += _OX;
	pt->y += _OY;
}

void	ft_add_step(t_coord *pt)
{
	pt->x *= __STEP;
	pt->y *= __STEP;
}

void	ft_cpyvertex(t_coord *dst, t_coord *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

t_bool	ft_checkinframe(int x, int y, int height, int width)
{
	if (x < 0 || y < 0 || x > width || y > height)
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_3d_to_2dbase(t_coord *pt)
{
	t_coord	*i;
	t_coord	*j;
	t_coord	*k;

	if (!pt || ft_alloc3pt(&i, &j, &k) == __FALSE)
		return (__FALSE);
	i->x = pt->x * sin(1.047197551214944);
	i->y = pt->x * cos(1.047197551214944);
	j->x = pt->y * (-sin(1.047197551214944) - ft_percent(__STEP, PERC_J));
	j->y = pt->y * (cos(1.047197551214944) + ft_percent(__STEP, PERC_J));
	k->x = pt->z * 0;
	k->y = pt->z * -1;
	pt->x = i->x;
	pt->y = i->y;
	pt->x += j->x;
	pt->y += j->y;
	pt->x += (k->x / ((double) __STEP)) * ft_percent(__STEP, PERC_K);
	pt->y += (k->y / ((double) __STEP)) * ft_percent(__STEP, PERC_K);
	pt->z = 0;
	ft_free3pt(&i, &j, &k);
	return (__TRUE);
}
