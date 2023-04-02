/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indextab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:03:37 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 15:06:37 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"

t_bool	ft_addindex(t_vars *xvar, int i)
{
	if (xvar->jx && xvar->i < xvar->jx)
		xvar->indxtab[xvar->i] = i;
	return (__TRUE);
}

void	ft_set_lenlist(t_vars *xvar)
{
	int	mx;
	int	i;

	i = 0;
	mx = 0;
	while (i < xvar->jx)
	{
		if (xvar->indxtab[i] > mx)
			mx = xvar->indxtab[i];
		i++;
	}
	xvar->lenlist = (mx - 1) * xvar->jx;
	xvar->lenlist += mx * (xvar->jx - 1);
}
