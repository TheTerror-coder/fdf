/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/27 13:54:35 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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
	free(params->p1);
	free(params->p2);
	free(params);
	exit(status);
}

// int	ft_cmpute_x(t_coord *a)
// {
// }

// void	ft_oxyz(t_coord *a)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	// x = ft_cmpute_x(a);
// 	// y = ft_cmpute_y(a);
// }

void	ft_vec_rot(t_coord *v, int phi)
{
	double	x;
	double	y;

	x = v->x * cos(phi) - v->y * sin(phi);
	y = v->y * sin(phi) + v->y * cos(phi);
	printf("cos: %f\n", cos(phi));
	printf("sin: %f\n", sin(phi));
	v->x = (int) x;
	v->y = (int) y;
	printf("x: %f\ny: %f\n", v->x, v->y);
}

double	ft_vec_norm(t_coord *o, t_coord *i)
{
	double	norm;

	norm = sqrt(pow(i->x - o->x, 2) + pow(i->y - o->y, 2));
	return (norm);
}

void ft_drwspot(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;

	o = ft_calloc(1, sizeof(t_coord));
	i = ft_calloc(1, sizeof(t_coord));
	o->x = 0;
	o->y = _OY;
	i->x = _WIDHT;
	i->y = _OY;
	ft_drw_line(xvar->img, o, i, 0xFFFFFF);
	o->x = _OX;
	o->y = 0;
	i->x = _OX;
	i->y = _HEIGHT;
	ft_drw_line(xvar->img, o, i, 0xFFFFFF);
	free(o);
	free(i);
}

void test(t_vars *xvar)
{
	t_coord *o;
	t_coord *i;

	o = ft_calloc(1, sizeof(t_coord));
	i = ft_calloc(1, sizeof(t_coord));
	o->x = _OX;
	o->y = _OY;
	i->x = _OX;
	i->y = _OY - __STEP;
	ft_drw_line(xvar->img, o, i, 0xFF00);
	i->x = _OX - __STEP * sin(1.047197551214944);
	i->y = _OY + __STEP * cos(1.047197551214944);
	ft_drw_line(xvar->img, o, i, 0xFF00);
	i->x = _OX + __STEP * sin(1.047197551214944);
	i->y = _OY + __STEP * cos(1.047197551214944);
	ft_drw_line(xvar->img, o, i, 0xFF00);
	free(o);
	free(i);
}

int	ft_fdf(t_vars *xvar)
{
	xvar->mlx = mlx_init();
	xvar->win = mlx_new_window(xvar->mlx, _SIZE_X, _SIZE_Y, "fdf project");
	xvar->img->image = mlx_new_image(xvar->mlx, _WIDHT, _HEIGHT);
	xvar->img->addr = mlx_get_data_addr(xvar->img->image, &(xvar->img->bpp), \
					&(xvar->img->size_line), &(xvar->img->endian));
	ft_drwspot(xvar);
	test(xvar);
	// ft_fdf_op(xvar);
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

/*int	ft_count_dgit(int n)
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

t_bool	ft_finddata(t_vars *xvar, char *line, int *i)
{
	int	n;

	n = 0;
	while (line[*i] && !ft_isdigit(line[*i]))
		*i += 1;
	if (!line[*i])
		return (__FALSE);
	n = ft_atoi(&line[*i]);
	xvar->p1->z = n;
	*i += ft_count_dgit(n);
	return (__TRUE);
}

void	ft_duppoint(t_vars *xvar)
{
	xvar->p2->x = xvar->p1->x;
	xvar->p2->y = xvar->p1->y;
	xvar->p2->z = xvar->p1->z;
}

void	ft_pxformat(t_vars *xvar)
{
	t_coord	*a;
	t_coord	*b;

	a = ft_calloc(1, sizeof(t_coord));
	b = ft_calloc(1, sizeof(t_coord));
	if (xvar->p2->x == 0 && xvar->p1->x == 0)
	{
		free(a);
		free(b);
		return ;
	}
	a->x = xvar->p1->x * __STEP - xvar->p1->z;
	a->y = xvar->p1->y * __STEP - (xvar->p1->z / 2);
	b->x = xvar->p2->x * __STEP - xvar->p2->z;
	b->y = xvar->p2->y * __STEP - (xvar->p2->z / 2);
	ft_drw_line(xvar->img, a, b, 0xFFFFFF);
}

t_bool	ft_trace(t_vars *xvar, char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (__FALSE);
	while (line[i])
	{
		if (ft_finddata(xvar, line, &i) == __TRUE)
		{
			ft_pxformat(xvar);
			ft_duppoint(xvar);
			xvar->p1->x++;
		}
		else
			return (__FALSE);
	}
	return (__TRUE);
}

t_bool	ft_fdf_op(t_vars *xvar)
{
	char	*line;
	char	*line_befor;

	xvar->p1->y = 0;
	xvar->p2->y = 0;
	line_befor = NULL;
	line = get_next_line(xvar->fd);
	while (line)// && xvar->p1->y != 1)
	{
		xvar->p2->x = 0;
		xvar->p1->x = 0;
		if (ft_trace(xvar, line) == __FALSE)
		{
			free(line);
			return (__FALSE);
		}
		if (line_befor)
		{
			free(line_befor);
		}
		line_befor = line;
		line = get_next_line(xvar->fd);
		xvar->p1->y++;
	}
	return (__TRUE);
}
*/