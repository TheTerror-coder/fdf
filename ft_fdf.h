/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/16 01:20:49 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "ft_preprocss.h"
# include "mlx.h"
# include<unistd.h>
# include<math.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include "./include/libft/libft.h"
# include "./utils/ft_utils.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
