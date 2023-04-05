/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:17:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 14:52:26 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"


void	ft_exitprocss(int status, t_vars *xvar)
{
	if (close(xvar->fd) == -1)
		status = EXIT_FAILURE;
	if (xvar->mlx)
	{
		if (xvar->img->image)
			mlx_destroy_image(xvar->mlx, xvar->img->image);
		if (xvar->win)
			mlx_destroy_window(xvar->mlx, xvar->win);
		mlx_destroy_display(xvar->mlx);
		free(xvar->mlx);
	}
	ft_free_tvars(xvar);
	if (status == EXIT_SUCCESS)
		printf("EXIT_SUCCESS\n");
	else
		printf("EXIT_FAILURE\n");
	exit(status);
}

double	ft_percent(double n, double per)
{
	double	res;

	res = per * n;
	res = ((double) res) / 100;
	return (res);
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
