/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:30:37 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 16:38:06 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_rotateright(t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	xvar->angle += 0.1;
	xvar->fdbk = ft_render(xvar);
	return (xvar->fdbk);
}

t_bool	ft_rotateleft(t_vars *xvar)
{
	xvar->fdbk = __TRUE;
	xvar->angle -= 0.1;
	xvar->fdbk = ft_render(xvar);
	return (xvar->fdbk);
}
