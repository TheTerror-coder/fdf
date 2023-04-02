/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:34:53 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 16:22:19 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getdata.h"

t_bool	ft_getdata_op(t_vars *xvar);
t_bool	ft_finddata(t_vars *xvar, char *line);
t_bool	ft_add_zdata(t_vars *xvar, char **data);
double	*ft_zdata(char **data);

t_bool	ft_getdata(t_vars *xvar)
{

	xvar->fdbk = __TRUE;
	if (ft_set_jx(xvar) == __FALSE)
		return (__FALSE);
	xvar->z_data = ft_calloc(xvar->jx, sizeof(double *));
	if (!xvar->z_data)
		return (__FALSE);
	xvar->indxtab = ft_calloc(xvar->jx, sizeof(int));
	if (!xvar->indxtab)
		return (__FALSE);
	xvar->i = 0;
	xvar->fdbk = ft_getdata_op(xvar);
	return (xvar->fdbk);
}

t_bool	ft_getdata_op(t_vars *xvar)
{
	char	*line;

	xvar->fdbk = __TRUE;
	line = NULL;
	line = get_next_line(xvar->fd);
	if (!line)
		return (__FALSE);
	while (line)
	{
		xvar->fdbk = ft_finddata(xvar, line);
		free(line);
		line = NULL;
		if (xvar->fdbk == __FALSE)
			return (__FALSE);
		line = get_next_line(xvar->fd);
		xvar->i++;
	}
	return (xvar->fdbk);
}

t_bool	ft_finddata(t_vars *xvar, char *line)
{
	char	**data;
	int		lendata;

	lendata = 0;
	xvar->fdbk = __TRUE;
	data = NULL;
	data = ft_split(line, ' ');
	if (!data)
		return (__FALSE);
	data = ft_keepnum(data);
	if (!data)
		return (__FALSE);
	lendata = ft_lensplit(data);
	if (xvar->fdbk == __TRUE)
		xvar->fdbk = ft_addindex(xvar, lendata);
	if (xvar->fdbk == __TRUE)
		xvar->fdbk = ft_add_zdata(xvar, data);
	ft_freesplit(data);
	return (xvar->fdbk);
}

t_bool	ft_add_zdata(t_vars *xvar, char **data)
{

	if (xvar->jx)
	{
		xvar->z_data[xvar->i] = ft_zdata(data);
		if (!xvar->z_data[xvar->i])
			return (__FALSE);
	}
	return (__TRUE);
}

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
