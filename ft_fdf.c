/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:53:38 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/08 17:39:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

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

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	int	x_px = 10;
	int	y_px = 100;
	int	color = 0x00FF0000;


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1820, 880, "Hello world");
	img.img = mlx_new_image(mlx_ptr, 1820, 880);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y_px < 700)
	{
		while (x_px < 1810)
		{
			my_mlx_pixel_put(&img, x_px, y_px, color);
			x_px++;
		}
		x_px = 10;
		y_px++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_string_put(mlx_ptr, win_ptr, 100, 200, 0x000000FF, "SCREEN!!!!!!");
	mlx_string_put(mlx_ptr, win_ptr, 200, 200, 0x0000FF00, "WINDOW");
	mlx_loop(mlx_ptr);

	return (0);
}
