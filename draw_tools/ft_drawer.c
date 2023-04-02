/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:55:08 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 17:00:50 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_draw_tools.h"

void	ft_drwin_3dspot(t_vars *xvar, t_coord *o, t_coord *e, int color)
{
	t_coord	*pt1;
	t_coord	*pt2;

	pt1 = ft_calloc(1, sizeof(t_coord));
	pt2 = ft_calloc(1, sizeof(t_coord));
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	ft_3d_to_2dbase(pt1);
	ft_3d_to_2dbase(pt2);
	ft_add_step(pt1);
	ft_add_step(pt2);
	ft_ad_in3dspot(pt1);
	ft_ad_in3dspot(pt2);
	ft_trace(xvar->img, pt1, pt2, color);
	free(pt1);
	free(pt2);
}

void	ft_drw_vector(t_vars *xvar, t_vec *vec, int	color)
{
	ft_drwin_3dspot(xvar, vec->o, vec->e, color);
}
