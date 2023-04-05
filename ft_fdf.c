/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/04/05 18:20:11 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		ft_fdf(t_vars *xvar);
void	ft_fdf_op(t_vars *xvar);
void	ft_exitprocss(int status, t_vars *xvar);

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
	if (ft_fdf(xvar) != __NTR)
		ft_exitprocss(EXIT_FAILURE, xvar);
	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (EXIT_SUCCESS);
}

int	ft_fdf(t_vars *xvar)
{
	if (ft_set_mlx(xvar) == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	if (ft_getdata(xvar) == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	if (ft_setvectors(xvar) == __FALSE)
		ft_exitprocss(EXIT_FAILURE, xvar);
	ft_fdf_op(xvar);
	mlx_put_image_to_window(xvar->mlx, xvar->win, xvar->img->image, 0, 0);
	mlx_hook(xvar->win, __ON_DESTROY, 0, ft_xbutton_destroy, xvar);
	mlx_hook(xvar->win, __ON_KEYDOWN, __KEYPRESSMASK, ft_keyhook, xvar);
	mlx_loop(xvar->mlx);
	return (__NTR);
}

void	ft_fdf_op(t_vars *xvar)
{
	int	i;

	i = 0;
	xvar->img->color = 0xe8f702;
	printf("Before\n");
	printf("lenlist= %d\n", xvar->lenlist);
	while (i < xvar->lenlist && xvar->list[i])
	{
		ft_drw_vector(xvar, xvar->list[i]);
		i++;
	}
	printf("i= %d\n", i);
	printf("total: %d\n", xvar->lenlist);
}
