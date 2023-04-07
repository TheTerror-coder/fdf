/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_altitude.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:20:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 17:34:06 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_lower(t_vars *xvar)
{
	xvar->height -= __HEIGHTSTEP;
	return (ft_render(xvar));
}

t_bool	ft_higher(t_vars *xvar)
{
	xvar->height += __HEIGHTSTEP;
	return (ft_render(xvar));
}
