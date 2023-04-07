/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:55:08 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 18:50:08 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_local.h"

t_bool	ft_drwin_3dspot(t_vars *xvar, t_coord *o, t_coord *e)
{
	t_coord	*pt1;
	t_coord	*pt2;

	xvar->fdbk = __TRUE;
	if (!o || !e || !xvar->img)
		return (__FALSE);
	if (ft_alloc2pt(&pt1, &pt2) == __FALSE)
		return (__FALSE);
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	xvar->fdbk = ft_3d_to_2dbase(xvar, pt1);
	if (xvar->fdbk == __TRUE)
		xvar->fdbk = ft_3d_to_2dbase(xvar, pt2);
	if (xvar->fdbk == __TRUE)
	{
		ft_add_step(xvar, pt1);
		ft_add_step(xvar, pt2);
		ft_ad_in3dspot(xvar, pt1);
		ft_ad_in3dspot(xvar, pt2);
		ft_trace(xvar->img, pt1, pt2);
	}
	ft_free2pt(&pt1, &pt2);
	return (xvar->fdbk);
}

t_bool	ft_drwin_2dspot(t_vars *xvar, t_coord *o, t_coord *e)
{
	t_coord	*pt1;
	t_coord	*pt2;

	xvar->fdbk = __TRUE;
	if (!o || !e || !xvar->img)
		return (__FALSE);
	if (ft_alloc2pt(&pt1, &pt2) == __FALSE)
		return (__FALSE);
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	if (xvar->fdbk == __TRUE)
	{
		ft_add_step(xvar, pt1);
		ft_add_step(xvar, pt2);
		ft_ad_in3dspot(xvar, pt1);
		ft_ad_in3dspot(xvar, pt2);
		ft_trace(xvar->img, pt1, pt2);
	}
	ft_free2pt(&pt1, &pt2);
	return (xvar->fdbk);
}

t_bool	ft_drw_vector(t_vars *xvar, t_vec *vec)
{
	xvar->fdbk = __TRUE;
	if (xvar->flg3d)
		xvar->fdbk = ft_drwin_3dspot(xvar, vec->o, vec->e);
	else if (xvar->fdbk == __TRUE)
	{
		if (!vec->o->z && !vec->e->z)
			xvar->fdbk = ft_drwin_2dspot(xvar, vec->o, vec->e);
	}
	return (xvar->fdbk);
}
