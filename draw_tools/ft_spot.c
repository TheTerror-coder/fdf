/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:08:10 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:49:00 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_local.h"

void	ft_drw_3dspot_op(t_vars *xvars, t_coord *o, t_coord *e);

void	ft_drw_2dspot(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;

	if (ft_alloc2pt(&o, &i) == __FALSE)
		return ;
	o->x = - _OX;
	o->y = 0;
	i->x = - _OX + _WIDHT;
	i->y = 0;
	ft_ad_in3dspot(o);
	ft_ad_in3dspot(i);
	xvar->img->color = 0xFFFFFF;
	ft_trace(xvar->img, o, i);
	o->x = 0;
	o->y = - _OY;
	i->x = 0;
	i->y = - _OY + _HEIGHT;
	ft_ad_in3dspot(o);
	ft_ad_in3dspot(i);
	ft_trace(xvar->img, o, i);
	ft_free2pt(&o, &i);
}

void	ft_drw_3dspot(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;
	t_coord *j;
	t_coord *k;

	if (!xvar->img || ft_alloc2pt(&o, &i) == __FALSE)
		return ;
	if (ft_alloc2pt(&j, &k) == __FALSE)
		return ;
	o->x = 0;
	o->y = 0;
	i->x = sin(1.047197551214944);
	i->y = cos(1.047197551214944);
	xvar->img->color = 0xFF;
	ft_drw_3dspot_op(xvar, o, i);
	j->x = - sin(1.047197551214944) - ft_percent(__STEP, PERC_J);
	j->y = cos(1.047197551214944) + ft_percent(__STEP, PERC_J);
	xvar->img->color = 0xFF0000;
	ft_drw_3dspot_op(xvar, o, j);
	k->x = 0;
	k->y = -1;
	xvar->img->color = 0xFF00;
	ft_drw_3dspot_op(xvar, o, k);
	ft_free2pt(&o, &i);
	ft_free2pt(&j, &k);
}

void	ft_drw_3dspot_op(t_vars *xvars, t_coord *o, t_coord *e)
{
	t_coord	*pt1;
	t_coord	*pt2;

	if (ft_alloc2pt(&pt1, &pt2) == __FALSE)
		return ;
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	ft_add_step(pt1);
	ft_add_step(pt2);
	ft_ad_in3dspot(pt1);
	ft_ad_in3dspot(pt2);
	ft_trace(xvars->img, pt1, pt2);
	ft_free2pt(&pt1, &pt2);
}
