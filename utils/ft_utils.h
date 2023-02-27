/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/02/24 16:24:36 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

#include "../ft_fdf.h"

void	ft_drw_line(t_img *img, t_coord *pt1, t_coord *pt2, int color);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int	ft_xbutton_destroy(t_vars *xvar);
int	ft_keyhook(int keycode, t_vars *xvar);
void	ft_freesplit(char **str);
t_vars	*ft_init_tvars();
int	ft_count_str(char **var);
t_bool	ft_checkextension(char	*name);
t_bool	ft_checkinframe(int val, int height, int width);

#endif