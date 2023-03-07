/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:44:28 by TheTerror         #+#    #+#             */
/*   Updated: 2023/03/07 18:37:53 by TheTerror        ###   ########lyon.fr   */
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
int	ft_lensplit(char **sstr);
t_bool	ft_checkextension(char	*name);
t_bool	ft_checkinframe(int val, int height, int width);
void	ft_ad_in3dspot(t_coord *pt);
void	ft_add_step(t_coord *pt);
void	ft_cpyvertex(t_coord *dst, t_coord *src);
void	ft_drwin_3dspot(t_vars *xvars, t_coord *o, t_coord *e, int color);
void	ft_drw_2dspot(t_vars *xvar);
void	ft_drw_3dspot(t_vars *xvar);
double	ft_percent(double n, double per);
void	ft_3d_to_2dbase(t_coord *pt);

#endif