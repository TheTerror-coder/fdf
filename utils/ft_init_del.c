/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/07 17:37:36 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_freesplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
	xvar->img = im;
	xvar->p1 = p1;
	xvar->p2 = p2;
	xvar->z_data = NULL;
	xvar->indxtab = NULL;
	// if (!xvar->img->image)
	// 	printf("xvar->img->image is Null\n");
	return (xvar);
}
