/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:17:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/03 16:56:58 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

double	ft_percent(double n, double per)
{
	double	res;

	res = per * n;
	res = ((double) res) / 100;
	return (res);
}

void	ft_ad_in3dspot(t_coord *pt)
{
	pt->x += _OX;
	pt->y += _OY;
}

void	ft_add_step(t_coord *pt)
{
	pt->x *= __STEP;
	pt->y *= __STEP;
}

void	ft_cpyvertex(t_coord *dst, t_coord *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

void	ft_drwin_3dspot(t_vars *xvars, t_coord *o, t_coord *e, int color)
{
	t_coord	*pt1;
	t_coord	*pt2;

	pt1 = ft_calloc(1, sizeof(t_coord));
	pt2 = ft_calloc(1, sizeof(t_coord));
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	ft_add_step(pt1);
	ft_add_step(pt2);
	ft_ad_in3dspot(pt1);
	ft_ad_in3dspot(pt2);
	ft_drw_line(xvars->img, pt1, pt2, color);
	free(pt1);
	free(pt2);
}

int	ft_count_str(char **var)
{
	int	i;

	i = 0;
	if (!var)
		return (0);
	while (var[i])
		i++;
	return (i);
}

t_bool	ft_checkextension(char	*name)
{
	char	**parts;

	parts = NULL;
	parts = ft_split(name, '.');
	if (!parts)
		return (__FALSE);
	if (ft_count_str(parts) != 2 || ft_strlen(parts[1]) != 3)
	{
		printf("format no valid!\n");
		ft_freesplit(parts);
		return (__FALSE);
	}
	if (ft_strncmp(parts[1] , "fdf", 3) == 0)
	{
		printf("format valid!\n");
		ft_freesplit(parts);
		return (__TRUE);
	}
	printf("warning error!\nformat no valid\n");
	ft_freesplit(parts);
	return (__FALSE);
}
