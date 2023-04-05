/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:58:12 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 14:59:18 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_free_tvars(t_vars *xvar)
{
	if (xvar->map)
		free(xvar->map);
	if (xvar->img)
		free(xvar->img);
	if (xvar->indxtab)
		free(xvar->indxtab);
	if (xvar->z_data)
		ft_freezdata(xvar);
	if (xvar->list)
		ft_free_listvec(xvar);
	free(xvar);
	xvar = NULL;
}

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_freezdata(t_vars *xvar)
{
	int	i;

	i = 0;
	if (xvar->z_data)
	{
		while (i < xvar->jx)
		{
			if (xvar->z_data[i])
				free(xvar->z_data[i]);
			xvar->z_data[i] = NULL;
			i++;
		}
		free(xvar->z_data);
		xvar->z_data = NULL;
	}
}

void	ft_free_listvec(t_vars *xvar)
{
	int	i;

	i = 0;
	if (!xvar->list)
		return ;
	while (i < xvar->lenlist && xvar->list[i])
	{
		ft_free_vect(xvar->list[i], xvar->list[i]->o, xvar->list[i]->e);
		i++;
	}
	free(xvar->list);
	xvar->list = NULL;
}

void	ft_free_vect(t_vec *vec, t_coord *o, t_coord *e)
{
	if (o)
		free(o);
	if (e)
		free(e);
	if (vec)
		free(vec);
	o = NULL;
	e = NULL;
	vec = NULL;
}
