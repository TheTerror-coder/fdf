/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setvectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:06:39 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 15:29:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"


void	ft_set_point(t_coord *pt, int x, int y, int z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}


t_bool	ft_collectdata2(t_vars *xvar, int i, int j)
{
	t_vec	*newvec;

	if (i < xvar->indxtab[j - 1])
	{
		newvec = ft_alloc_vect(1, sizeof(t_vec));
		if (!newvec)
			return (__FALSE);
		ft_set_point(newvec->e, i, j, xvar->z_data[j][i]);
		ft_set_point(newvec->o, i, j - 1, xvar->z_data[j - 1][i]);
		if (xvar->ix_list < xvar->lenlist)
		{
			xvar->list[xvar->ix_list] = newvec;
			xvar->ix_list++;
		}
	}
	return (__TRUE);
}

t_bool	ft_collect_col(t_vars *xvar)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < xvar->jx)
	{
		if (j > 0)
		{
			i = 0;
			while (i < xvar->indxtab[j])
			{
				if (ft_collectdata2(xvar, i, j) == __FALSE)
					return (__FALSE);
				i++;
			}
		}
		j++;
	}
	return (__TRUE);
}

t_bool	ft_collectdata1(t_vars *xvar, int i, int j)
{
	t_vec	*newvec;

	newvec = ft_alloc_vect(1, sizeof(t_vec));
	if (!newvec)
		return (__FALSE);
	ft_set_point(newvec->o, i - 1, j, xvar->z_data[j][i - 1]);
	ft_set_point(newvec->e, i, j, xvar->z_data[j][i]);
	if (xvar->ix_list < xvar->lenlist)
	{
		xvar->list[xvar->ix_list] = newvec;
		xvar->ix_list++;
	}
	return (__TRUE);
}

t_bool	ft_collect_line(t_vars *xvar)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < xvar->jx)
	{
		i = 0;
		while (i < xvar->indxtab[j])
		{
			if (i > 0)
			{
				if (ft_collectdata1(xvar, i, j) == __FALSE)
					return (__FALSE);
			}
			i++;
		}
		j++;
	}
	return (__TRUE);
}

t_bool	ft_setvectors(t_vars *xvar)
{
	if (!xvar->z_data || !xvar->indxtab)
		return (__TRUE);
	ft_set_lenlist(xvar);
	xvar->list = ft_calloc(xvar->lenlist, sizeof(t_vec *));
	if (!xvar->list)
		return (__FALSE);
	if (ft_collect_line(xvar) == __FALSE)
		return (__FALSE);
	if (ft_collect_col(xvar) == __FALSE)
		return (__FALSE);
	return (__TRUE);
}
