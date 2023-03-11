/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:34:53 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/11 16:46:10 by TheTerror        ###   ########lyon.fr   */
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

t_bool	ft_cpyzdata(t_vars *xvar, double **dest, double **src, int nline)
{
	int	j;

	j = 0;
	while (j < nline)
	{
		dest[j] = ft_calloc(xvar->indxtab[j], sizeof(double));
		if (!dest[j])
		{
			j--;
			while (j >= 0)
			{
				if (dest[j])
					free(dest[j]);
				dest[j] = NULL;
				j--;
			}
			return (__FALSE);
		}
		dest[j] = ft_memmove(dest[j], src[j], sizeof(double) * xvar->indxtab[j]);
		j++;
	}
	return (__TRUE);
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
		if (ft_cpyzdata(xvar, tab, xvar->z_data, xvar->jx - 1) == __FALSE)
		{
			free(tab);
			return (__FALSE);
		}
		tab[xvar->jx - 1] = ft_zdata(data);
		if (!tab[xvar->jx - 1])
		{
			ft_freezdata(tab, xvar->jx - 1);
			return (__FALSE);
		}
	}
	if (xvar->z_data)
		ft_freezdata(xvar->z_data, xvar->jx - 1);
	xvar->z_data = tab;
	return (__TRUE);
}

t_bool	ft_finddata(t_vars *xvar, char *line)
{
	char	**data;

	xvar->fdbk = __TRUE;
	data = NULL;
	data = ft_split(line, ' ');
	if (!data)
		return (__FALSE);
	xvar->n = ft_lensplit(data);
	if (xvar->fdbk == __TRUE)
		xvar->fdbk = ft_addindex(xvar, xvar->n);
	if (xvar->fdbk == __TRUE)
		xvar->fdbk = ft_add_zdata(xvar, data);
	ft_freesplit(data);
	return (xvar->fdbk);
}

t_bool	ft_getdata(t_vars *xvar)
{
	char	*line;

	xvar->fdbk = __TRUE;
	line = NULL;
	xvar->jx = 0;
	line = get_next_line(xvar->fd);
	if (!line)
		return (__FALSE);
	while (line)
	{
		printf ("HHHHHHHHHH\n");
		xvar->jx++;
		xvar->fdbk = ft_finddata(xvar, line);
		free(line);
		line = NULL;
		if (xvar->fdbk == __FALSE)
			return (__FALSE);
		line = get_next_line(xvar->fd);
	}
	return (__TRUE);
}
