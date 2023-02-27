/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/18 15:48:36 by TheTerror        ###   ########lyon.fr   */
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
	t_vars	*var;
	t_img	*im;
	t_coord	*p1;
	t_coord	*p2;
	
	var = ft_calloc(1, sizeof(t_vars));
	im = ft_calloc(1, sizeof(t_img));
	p1 = ft_calloc(1, sizeof(t_coord));
	p2 = ft_calloc(1, sizeof(t_coord));
	var->img = im;
	var->p1 = p1;
	var->p2 = p2;
	// if (!var->img->image)
	// 	printf("var->img->image is Null\n");
	return (var);
}
