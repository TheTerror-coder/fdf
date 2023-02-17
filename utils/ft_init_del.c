/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:41:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/17 19:44:50 by TheTerror        ###   ########lyon.fr   */
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
	
	var = ft_calloc(1, sizeof(t_vars));
	im = ft_calloc(1, sizeof(t_img));
	var->img = im;
	// if (!var->img->image)
	// 	printf("var->img->image is Null\n");
	return (var);
}
