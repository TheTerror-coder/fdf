/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 15:00:25 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_vec	*ft_alloc_vect(unsigned int nmemb, unsigned int size)
{
	t_vec	*vec;
	t_coord	*o;
	t_coord	*e;

	o = NULL;
	e = NULL;
	vec = NULL;
	o = ft_calloc(1, sizeof(t_coord));
	e = ft_calloc(1, sizeof(t_coord));
	vec = ft_calloc(nmemb, size);
	if (!o || !e || !vec)
	{
		ft_free_vect(vec, o, e);
		return (NULL);
	}
	vec->o = o;
	vec->e = e;
	return (vec);
}

t_vars	*ft_init_tvars()
{
	t_vars	*xvar;
	t_img	*im;
	
	xvar = ft_calloc(1, sizeof(t_vars));
	im = ft_calloc(1, sizeof(t_img));
	xvar->fd = 0;
	xvar->map = NULL;
	xvar->mlx = NULL;
	xvar->win = NULL;
	xvar->img = im;
	xvar->indxtab = NULL;
	xvar->z_data = NULL;
	xvar->list = NULL;
	xvar->ix_list = 0;
	xvar->lenlist = 0;
	xvar->jx = 0;
	xvar->i = 0;
	xvar->fdbk = __TRUE;
	return (xvar);
}
