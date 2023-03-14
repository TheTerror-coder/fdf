/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/13 19:09:26 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

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

void	ft_freezdata(double **arr2, int nline)
{
	int	i;

	i = 0;
	if (arr2)
	{
		while (i < nline)
		{
			if (arr2[i])
				free(arr2[i]);
			arr2[i] = NULL;
			i++;
		}
		free(arr2);
		arr2 = NULL;
	}
}

void	ft_free_listvec(t_vec **list)
{
	int	i;

	i = 0;
	if (!list)
		return ;
	while (list[i])
	{
		ft_free_vect(list[i], list[i]->o, list[i]->e);
		i++;
	}
	free(list);
	list = NULL;
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

t_vec	**ft_alloclist_vec(unsigned int nmemb, unsigned int size)
{
	unsigned int	i;
	t_vec			**list;
	t_vec			*vec;

	i = 0;
	list = NULL;
	vec = NULL;
	list = ft_calloc(nmemb, size);
	if (!list)
		return (NULL);
	while (i < nmemb - 1)
	{
		vec = ft_alloc_vect(1, sizeof(t_vec));
		if (!vec)
		{
			list[i] = NULL;
			ft_free_listvec(list);
			return (NULL);
		}
		list[i] = vec;
		i++;
	}
	list[i] = NULL;
	return (list);
}

t_vars	*ft_init_tvars()
{
	t_vars	*xvar;
	t_img	*im;
	t_coord	*p1;
	t_coord	*p2;
	
	xvar = ft_calloc(1, sizeof(t_vars));
	im = ft_calloc(1, sizeof(t_img));
	p1 = ft_calloc(1, sizeof(t_coord));
	p2 = ft_calloc(1, sizeof(t_coord));
	xvar->fd = 0;
	xvar->img = im;
	xvar->p1 = p1;
	xvar->p2 = p2;
	xvar->indxtab = NULL;
	xvar->z_data = NULL;
	xvar->list = NULL;
	xvar->jx = 0;
	xvar->n = 0;
	xvar->fdbk = __TRUE;
	// if (!xvar->img->image)
	// 	printf("xvar->img->image is Null\n");
	return (xvar);
}
