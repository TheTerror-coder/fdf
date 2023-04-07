/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:42:35 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 17:12:48 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_zoomin(t_vars *xvar)
{
	int	n;

	n = __ZOOMSTEP;
	xvar->fdbk = __TRUE;
	if (!xvar->flgzoom)
		xvar->zmstep += n;
	xvar->zmstep += n;
	xvar->fdbk = ft_render(xvar);
	xvar->flgzoom = 1;
	return (xvar->fdbk);
}

t_bool	ft_zoomout(t_vars *xvar)
{
	int	n;

	n = __ZOOMSTEP;
	xvar->fdbk = __TRUE;
	if (xvar->flgzoom)
	{
		xvar->zmstep -= n;
		if ((__STEP + xvar->zmstep) > 0)
			xvar->fdbk = ft_render(xvar);
		else
			xvar->flgzoom = 0;
	}
	return (xvar->fdbk);
}
