/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changeview.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:53:43 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 16:59:15 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_flat(t_vars *xvar)
{
	xvar->flg3d = !xvar->flg3d;
	return (ft_render(xvar));
}
