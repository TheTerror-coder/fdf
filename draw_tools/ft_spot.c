/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:08:10 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 17:14:27 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_draw_tools.h"

void	ft_drw_3dspot_op(t_vars *xvars, t_coord *o, t_coord *e, int color);

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
	ft_trace(xvar->img, o, i, 0xFFFFFF);
	o->x = 0;
	o->y = - _OY;
	i->x = 0;
	i->y = - _OY + _HEIGHT;
	ft_ad_in3dspot(o);
	ft_ad_in3dspot(i);
	ft_trace(xvar->img, o, i, 0xFFFFFF);
	free(o);
	free(i);
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
	ft_trace(xvars->img, pt1, pt2, color);
	free(pt1);
	free(pt2);
}
