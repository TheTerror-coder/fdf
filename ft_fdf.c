/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/02 17:23:02 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"


void	ft_exitprocss(int status, t_vars *xvar)
{
	if (close(xvar->fd) == -1)
		status = EXIT_FAILURE;
	if (xvar->mlx)
	{
		if (xvar->img->image)
			mlx_destroy_image(xvar->mlx, xvar->img->image);
		mlx_clear_window(xvar->mlx, xvar->win);
		mlx_destroy_window(xvar->mlx, xvar->win);
	}
	if (status == EXIT_SUCCESS)
		printf("EXIT_SUCCESS\n");
	else
		printf("EXIT_FAILURE\n");
	free(xvar->img);
	free(xvar->p1);
	free(xvar->p2);
	ft_freezdata(xvar->z_data, xvar->jx);
	free(xvar->indxtab);
	free(xvar);
	exit(status);
}

void test1(t_vars *xvar)
{
	int	i;
	int	color = 0xe8f702;
	// int	j;

	// i = 0;
	// j = 0;
	// while (j < xvar->jx)
	// {
	// 	i = 0;
	// 	// printf("j = %d\n", j);
	// 	while (i < xvar->indxtab[j])
	// 	{
	// 		printf("%.1f ", xvar->z_data[j][i]);
	// 		i++;
	// 	}
	// 	printf("\n");
	// 	j++;
	// }

	// i = 0;
	// while (i < xvar->jx)
	// {
	// 	printf("jx: %d -> length: %d\n", i, xvar->indxtab[i]);
	// 	i++;
	// }
	i = 0;
	printf("Before\n");
	printf("lenlist= %d\n", xvar->lenlist);
	while (i < xvar->lenlist && xvar->list[i])
	{
		ft_drw_vector(xvar, xvar->list[i], color);
		i++;
	}
	printf("i= %d\n", i);
	printf("total: %d\n", i);
	printf("total: %d\n", xvar->lenlist);
}

int	ft_fdf(t_vars *xvar)
{
	xvar->mlx = mlx_init();
	xvar->win = mlx_new_window(xvar->mlx, _SIZE_X, _SIZE_Y, "fdf project");
	xvar->img->image = mlx_new_image(xvar->mlx, _WIDHT, _HEIGHT);
	xvar->img->addr = mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	// ft_drw_2dspot(xvar);
	// ft_drw_3dspot(xvar);
	ft_getdata(xvar);
	ft_setvectors(xvar);
	test1(xvar);
	// test(xvar);
	// ft_fdf_op(xvar);
		my_mlx_pixel_put(xvar->img, 1800, 500, 0xFFFFFF);

	mlx_put_image_to_window(xvar->mlx, xvar->win, xvar->img->image, 0, 0);
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
	xvar->map = ft_strdup(argv[1]);
	if (!xvar->map)
		ft_exitprocss(EXIT_FAILURE, xvar);
	xvar->fd = open(xvar->map, O_RDONLY);
	if (xvar->fd == -1)
		ft_exitprocss(EXIT_FAILURE, xvar);
	ft_fdf(xvar);

	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (EXIT_SUCCESS);
}

