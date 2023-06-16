/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:42:35 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/16 16:16:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_zoomin(t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	xvar->zmstep += __ZOOMSTEP;
	xvar->fdbk = ft_render(xvar);
	return (xvar->fdbk);
}

t_bool	ft_zoomout(t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	if (xvar->flgzoom)
	{
		xvar->zmstep -= __ZOOMSTEP;
		if ((__STEP + xvar->zmstep) > 0)
			xvar->fdbk = ft_render(xvar);
		else
			xvar->flgzoom = 0;
	}
	return (xvar->fdbk);
}
