/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/10 18:02:00 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include<stdio.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	wclose(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	(void) keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, wclose, &vars);
	mlx_loop(vars.mlx);

	return (0);
}

/*
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_printable(char *s)
{
	int	i;

	i = 0;
	while (s[i] && "10"[i])
	{
		if (s[i] != "10"[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	fd;
	int	i;
	int	index = 0;
	int	x_str = 0;
	int	x_offset = 100;
	int	y_str = 0;
	int	y_offset = 200;
	int	color = 0x00FF0000;
	int	len_read = -999;
	char	*buffer;
	char	*data;

	buffer = ft_calloc(11, 1);
	data = ft_calloc(11, 1);
	if (!data || !buffer)
		return (-1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1820, 880, "Hello world");
	fd = open("maps/test_maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (len_read != 0 && len_read != -1)
	{
		len_read = read(fd, buffer, 10);
		if (len_read != -1 && len_read != 0)
		{
			buffer[len_read] = 0;
			index = 0;
			while (buffer[index])
			{
				if (buffer[index] == '\n')
				{
					x_str = 0;
					index++;
					y_str += 15;
					// printf("\n");
				}
				else if (ft_isdigit(buffer[index]))
				{
					i = 0;
					while (ft_isdigit(buffer[index]))
					{
						data[i] = buffer[index];
						index++;
						i++;
					}
					data[i] = 0;
					// printf("%s", data);
					mlx_string_put(mlx_ptr, win_ptr, x_str + x_offset, y_str + y_offset, color, data);
					x_str += i * 6;
				}
				else
				{
					index++;
					x_str += 6;
				}
			}
		}
	}
	// if (len_read == -1)
	// 	printf("read() failed");
	// if (len_read == 0)
	// 	printf("read() success");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 500, color, "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 515, color, "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 530, color, "0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 545, color, "0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 560, color, "0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 575, color, "0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 590, color, "0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 605, color, "0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 620, color, "0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 635, color, "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(mlx_ptr, win_ptr, 1000, 650, color, "0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_loop(mlx_ptr);
	close(fd);
	free(buffer);
	free(data);
	return (0);
}
*/