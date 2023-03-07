/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:34:53 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/07 19:35:12 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"

double	*ft_zdata(char **data)
{
	int		i;
	double	*tab;

	i = 0;
	tab = NULL;
	if (!data)
		return (NULL);
	tab = ft_calloc(ft_lensplit(data), sizeof(double));
	if (!tab)
		return (NULL);
	while(data[i])
	{
		tab[i] = (double) ft_atoi(data[i]);
		i++;
	}
	return (tab);
}

void	ft_freezdata(t_vars *xvar)
{
	int	i;

	i = 0;
	if (xvar->z_data)
	{
		while (i < (xvar->jx - 1))
		{
			free(xvar->z_data[i]);
			xvar->z_data[i] = NULL;
			i++;
		}
		free(xvar->z_data);
		xvar->z_data = NULL;
	}
}

t_bool	ft_add_zdata(t_vars *xvar, char **data)
{
	double	**tab;

	tab = NULL;
	if (xvar->jx)
	{
		tab = ft_calloc(xvar->jx, sizeof(double *));
		if (!tab)
			return (__FALSE);
		ft_memmove(tab, xvar->z_data, sizeof(double *) * (xvar->jx - 1));
		tab[xvar->jx - 1] = ft_zdata(data);
	}
	if (xvar->z_data)
		ft_freezdata(xvar);
	xvar->z_data = tab;
	return (__TRUE);
}

t_bool	ft_finddata(t_vars *xvar, char *line)
{
	char	**data;

	data = NULL;
	data = ft_split(line, ' ');
	if (!data)
		return (__FALSE);
	xvar->n = ft_lensplit(data);
									/*A revoir*/ft_addindex(xvar, xvar->n);
	ft_add_zdata(xvar, data);
	ft_freesplit(data);
	return (__TRUE);
}

t_bool	ft_getdata(t_vars *xvar)
{
	char	*line;

	xvar->jx = 0;
	line = get_next_line(xvar->fd);
	if (!line)
		return (__FALSE);
	while (line)
	{
		xvar->jx++;
		ft_finddata(xvar, line);
		free(line);
		line = NULL;
		line = get_next_line(xvar->fd);
	}
	return (__TRUE);
}