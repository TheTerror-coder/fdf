/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:17:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/13 19:09:37 by TheTerror        ###   ########lyon.fr   */
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

void	ft_3d_to_2dbase(t_coord *pt)
{
	t_coord *i;
	t_coord *j;
	t_coord *k;

	i = ft_calloc(1, sizeof(t_coord));
	j = ft_calloc(1, sizeof(t_coord));
	k = ft_calloc(1, sizeof(t_coord));
	i->x = pt->x * sin(1.047197551214944);
	i->y = pt->x * cos(1.047197551214944);
	j->x = pt->y * (- sin(1.047197551214944) - ft_percent(__STEP, PERC_J));
	j->y = pt->y * (cos(1.047197551214944) + ft_percent(__STEP, PERC_J));
	k->x = pt->z * 0;
	k->y = pt->z * -1;
	pt->x = i->x;
	pt->y = i->y;
	pt->x += j->x;
	pt->y += j->y;
	pt->x += (k->x  / ((double) __STEP)) * ft_percent(__STEP, PERC_K);
	pt->y += (k->y / ((double) __STEP)) * ft_percent(__STEP, PERC_K);
	pt->z = 0;
	free(i);
	free(j);
	free(k);
}

void	ft_drwin_3dspot(t_vars *xvar, t_coord *o, t_coord *e, int color)
{
	t_coord	*pt1;
	t_coord	*pt2;

	pt1 = ft_calloc(1, sizeof(t_coord));
	pt2 = ft_calloc(1, sizeof(t_coord));
	ft_cpyvertex(pt1, o);
	ft_cpyvertex(pt2, e);
	ft_3d_to_2dbase(pt1);
	ft_3d_to_2dbase(pt2);
	ft_add_step(pt1);
	ft_add_step(pt2);
	ft_ad_in3dspot(pt1);
	ft_ad_in3dspot(pt2);
	ft_drw_line(xvar->img, pt1, pt2, color);
	free(pt1);
	free(pt2);
}

void	ft_drw_vector(t_vars *xvar, t_vec *vec, int	color)
{
	ft_drwin_3dspot(xvar, vec->o, vec->e, color);
}

int	ft_lensplit(char **sstr)
{
	int	i;

	i = 0;
	if (!sstr)
		return (0);
	while (sstr[i])
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
	if (ft_lensplit(parts) != 2 || ft_strlen(parts[1]) != 3)
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
