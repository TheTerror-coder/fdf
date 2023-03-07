/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indextab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:03:37 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/07 18:07:34 by TheTerror        ###   ########lyon.fr   */
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
		ft_memmove(tab, xvar->indxtab, sizeof(int) * (xvar->jx - 1));
		tab[xvar->jx - 1] = i;
	}
	if (xvar->indxtab)
		free(xvar->indxtab);
	xvar->indxtab = tab;
	return (__TRUE);
}