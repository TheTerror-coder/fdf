/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/15 22:49:01 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include<stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_join_pt(t_data *data, double x0, double m, t_coord *pt, int color)
{
	double	y;

	y = 0;
	while (x0 <= pt->x)
	{
		y = m * x0 + (pt->y - m * pt->x);
		if (y >= 0)
			my_mlx_pixel_put(data, x0, y, color);
		x0++;
	}
	printf("x = %f\n", x0);
	printf("y = %f\n", y);
}

void	ft_vert_line(t_data *data, double y0, t_coord *pt, int color)
{
	double	x;

	x = pt->x;
	while (y0 <= pt->y)
	{
		my_mlx_pixel_put(data, x, y0, color);
		y0++;
	}
}

void	ft_hor_line(t_data *data, double x0, t_coord *pt, int color)
{
	double	y;

	y = pt->y;
	while (x0 <= pt->x)
	{
		my_mlx_pixel_put(data, x0, y, color);
		x0++;
	}
}

void	ft_drw_line(t_data *data, t_coord *pt1, t_coord *pt2, int color)
{
	double	dx;
	double	dy;

	dx = pt2->x - pt1->x;
	dy = (pt2->y - pt1->y);
	if (dx == 0)
	{
		if (dy < 0)
			ft_vert_line(data, pt2->y, pt1, color);
		if (dy > 0)
			ft_vert_line(data, pt1->y, pt2, color);
	}
	else if (dy == 0)
	{
		if (dx < 0)
			ft_hor_line(data, pt2->x, pt1, color);
		if (dx > 0)
			ft_hor_line(data, pt1->x, pt2, color);
	}
	else if (dx < 0)
		ft_join_pt(data, pt2->x, (dy / dx), pt1, color);
	else if (dx > 0)
		ft_join_pt(data, pt1->x, (dy / dx), pt2, color);
	printf("m = %f\n", dx);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	t_coord	*pt1 = ft_calloc(1, sizeof(t_coord));
	t_coord *pt2 = ft_calloc(1, sizeof(t_coord));
	t_coord *pt3 = ft_calloc(1, sizeof(t_coord));
	t_coord *pt4 = ft_calloc(1, sizeof(t_coord));
	int	color = 0x00FFFFFF;

	pt1->x = 15;
	pt1->y = 60;
	pt1->z = 0;

	pt2->x = 15;
	pt2->y = 30;
	pt2->z = 0;

	pt3->x = 30;
	pt3->y = 45;
	pt3->z = 10;
	
	pt4->x = 60;
	pt4->y = 30;
	pt4->z = 10;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1820, 880, "Hello world");
	img.img = mlx_new_image(mlx_ptr, 1820, 880);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	ft_drw_line(&img, pt1, pt2, color);
	ft_drw_line(&img, pt2, pt3, color);
	ft_drw_line(&img, pt3, pt4, color);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	// mlx_string_put(mlx_ptr, win_ptr, 100, 200, 0x000000FF, "SCREEN!!!!!!");
	// mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0x0000FF00, "WINDOW");
	mlx_loop(mlx_ptr);

	return (0);
}

/*
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
	xvar->img->image = mlx_new_image(xvar->mlx, 1200, 500);
	xvar->img->addr = mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	mlx_put_image_to_window(xvar->mlx, xvar->win, xvar->img->image, 0, 0);
	// printf("i'm here\n");
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
*/