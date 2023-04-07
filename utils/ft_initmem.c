/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/07 16:49:24 by TheTerror        ###   ########lyon.fr   */
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
	if (!xvar)
		return (NULL);
	im = ft_calloc(1, sizeof(t_img));
	if (!im)
	{
		free (xvar);
		return (NULL);
	}
	xvar->img = im;
	xvar->fdbk = __TRUE;
	xvar->flgzoom = 1;
	xvar->flg3d = 1;
	return (xvar);
}
