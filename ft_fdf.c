/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/12 14:12:55 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include<stdio.h>

void	ft_exitprocss(int status, t_vars *params)
{
	if (close(params->fd) == -1)
		status = EXIT_FAILURE;
	if (params->mlx)
	{
		if (params->img->image)
			mlx_destroy_image(params->mlx, params->img->image);
		mlx_clear_window(params->mlx, params->win);
		mlx_destroy_window(params->mlx, params->win);
	}
	if (status == EXIT_SUCCESS)
		printf("EXIT_SUCCESS\n");
	else
		printf("EXIT_FAILURE\n");
	free(params->img);
	free(params);
	exit(status);
}

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
	printf("warniong error!\nformat no valid\n");
	ft_freesplit(parts);
	return (__FALSE);
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

int	ft_xbutton_destroy(t_vars *xvar)
{
	printf("xbutton pressed\n");
	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (0);
}

int	ft_keyhook(int keycode, t_vars *xvar)
{
	printf("keypressed code: %d\n", keycode);
	if (keycode == __ESC)
		ft_exitprocss(EXIT_SUCCESS, xvar);
	return (0);
}

int	ft_fdf(t_vars *xvar)
{
	xvar->mlx = mlx_init();
	xvar->win = mlx_new_window(xvar->mlx, 1900, 880, "fdf project");
/*	xvar->img->image = mlx_new_image(xvar->mlx, 1200, 500);
	mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	mlx_put_image_to_window(xvar->mlx, xvar->win, xvar->img->image, 0, 0);
*/	// printf("i'm here\n");
	mlx_hook(xvar->win, __ON_DESTROY, 0, ft_xbutton_destroy, xvar);
	mlx_hook(xvar->win, __ON_KEYDOWN, __KEYPRESSMASK, ft_keyhook, xvar);
	mlx_loop(xvar->mlx);
	return (__NTR);
}

int	main(int argc, char *argv[])
{
	t_vars	*xvar;

	xvar = ft_init_tvars();
	if (argc < 2)
		ft_exitprocss(EXIT_FAILURE, xvar);
	if (ft_checkextension(argv[1]) == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	xvar->fd = open(argv[1], O_RDONLY);
	if (xvar->fd == -1)
		ft_exitprocss(EXIT_FAILURE, xvar);
	ft_fdf(xvar);

	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (EXIT_SUCCESS);
}
