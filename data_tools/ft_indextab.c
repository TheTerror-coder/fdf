/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indextab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:03:37 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/31 18:42:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"

t_bool	ft_addindex(t_vars *xvar, int i)
{
	int	*tab;

	tab = NULL;
	if (xvar->jx)
	{
		tab = calloc(xvar->jx, sizeof(int));
		if (!tab)
			return (__FALSE);
		tab = ft_memmove(tab, xvar->indxtab, sizeof(int) * (xvar->jx - 1));
		tab[xvar->jx - 1] = i;
	}
	if (xvar->indxtab)
		free(xvar->indxtab);
	xvar->indxtab = NULL;
	xvar->indxtab = tab;
	return (__TRUE);
}

void	ft_set_lenlist(t_vars *xvar)
{
	if (xvar->indxtab && xvar->indxtab[0])
	{
		xvar->lenlist = (xvar->indxtab[0] - 1) * xvar->jx;
		xvar->lenlist += (xvar->indxtab[0]) * (xvar->jx - 1);
	}
}
