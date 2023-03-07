/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/07 18:41:22 by TheTerror        ###   ########lyon.fr   */
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
	free(xvar);
	exit(status);
}


void	test(t_vars *xvar)
{
	t_coord *o;
	t_coord *a;
	t_coord *b;
	t_coord *c;
	t_coord *d;
	int	color = 0xe8f702;

	o = ft_calloc(1, sizeof(t_coord));
	a = ft_calloc(1, sizeof(t_coord));
	b = ft_calloc(1, sizeof(t_coord));
	c = ft_calloc(1, sizeof(t_coord));
	d = ft_calloc(1, sizeof(t_coord));
	o->x = 0;
	o->y = 0;
	a->x = 1;
	a->y = 1;
	a->z = 0;
	b->x = 2;
	b->y = 1;
	b->z = 0;
	c->x = 1;
	c->y = 2;
	c->z = 0;
	d->x = 2;
	d->y = 2;
	d->z = 10;
	ft_drwin_3dspot(xvar, a, b, color);
	ft_drwin_3dspot(xvar, a, c, color);
	ft_drwin_3dspot(xvar, c, d, color);
	ft_drwin_3dspot(xvar, b, d, color);
	free(o);
	free(a);
	free(b);
	free(c);
	free(d);
}

int	ft_count_dgit(int n)
{
	int len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
void	ft_getdatas(double *dest, char **src)
{
	int	i;

	i = 0;
	if (!src || !dest)
		return ;
	while (src[i])
	{
		dest[i] = (double) ft_atoi(src[i]);
		i++;
	}
}


void test1()
{
	int i;
	char	**data;

	i = 0;
	data = NULL;
	data = ft_split("aIS SIQAE IEUEH FEHI", ' ');
	while (data[i])
	{
		printf("data: %s\n", data[i]);
		i++;
	}
	printf("len: %d\n", ft_lensplit(data));
	ft_freesplit(data);
}

int	ft_fdf(t_vars *xvar)
{
	xvar->mlx = mlx_init();
	xvar->win = mlx_new_window(xvar->mlx, _SIZE_X, _SIZE_Y, "fdf project");
	xvar->img->image = mlx_new_image(xvar->mlx, _WIDHT, _HEIGHT);
	xvar->img->addr = mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	ft_drw_2dspot(xvar);
	ft_drw_3dspot(xvar);
	test1();
	// test(xvar);
	// ft_fdf_op(xvar);
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
	xvar->fd = open(argv[1], O_RDONLY);
	if (xvar->fd == -1)
		ft_exitprocss(EXIT_FAILURE, xvar);
	ft_fdf(xvar);

	ft_exitprocss(EXIT_SUCCESS, xvar);
	return (EXIT_SUCCESS);
}

