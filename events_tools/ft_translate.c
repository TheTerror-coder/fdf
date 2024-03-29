/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 01:30:01 by TheTerror         #+#    #+#             */
/*   Updated: 2023/06/16 18:26:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_events_tools.h"

t_bool	ft_render(t_vars *xvar);

t_bool	ft_translateleft(t_vars *xvar)
{
	xvar->horstep -= __SHIFTSTEP;
	return (ft_render(xvar));
}

t_bool	ft_translateright(t_vars *xvar)
{
	xvar->horstep += __SHIFTSTEP;
	return (ft_render(xvar));
}

t_bool	ft_translateup(t_vars *xvar)
{
	xvar->vertstep -= __SHIFTSTEP;
	return (ft_render(xvar));
}

t_bool	ft_translatedown(t_vars *xvar)
{
	xvar->vertstep += __SHIFTSTEP;
	return (ft_render(xvar));
}
